/*  main.c  - main */
/*
 * Grading test case for CS354 Lab5 Problem 4 (18spring), Xuankang Lin
 */

#include <xinu.h>


#define SLP_PERIOD (100)

#define RET_OK (20)
#define RET_TIMEOUT (21)
#define RET_ERR (22)

#define OP_SND_NONE (30) // send back nothing
#define OP_SND_TIME (31) // send back time usage for sendb()
#define OP_SND_RC (32) // send back return code of sendb()

#define MSG1 (1992) // just a default message


/** register a callback function of a message buffer. */
typedef int (*msgcb)(void);
syscall cbreg(msgcb cb);

local pid32 s_mp; // main process, because callback function doesn't know main pid


/**
 * Otherwise, return code TIMEOUT, and recvtime() TIMEOUT cannot distinguish.
 */
local umsg32 ret_msg(uint32 ret) {
	switch (ret) {
	case SYSERR:
		return RET_ERR;

	case TIMEOUT:
		// otherwise it cannot distinguish TIMEOUT return code from no message
		return RET_TIMEOUT;

	case OK:
		return RET_OK;

	default:
		return ret;
	}
}

// ==========

/**
 * Customizable process that calls registercb()
 */
local void registercb_proc(msgcb cb, uint32 opcode) {
	recvclr(); // clear existing message, if any (unlikely)

	uint32 rc = cbreg(cb);

	switch (opcode) {
	case OP_SND_RC: {
		send(s_mp, ret_msg(rc));
		break;
	}

	default:
		break;
	}

	/*
	 * Should not terminate by itself, otherwise kill() will send some message to
	 * the parent (main), which may mess up with existing messages.
	 */
	while (TRUE) {
		// this is to have some chance of actually running the callback function
		sleepms(SLP_PERIOD);
	}
}


/**
 * Customizable process that sends message to a process that registered cb.
 */
local void p2send_proc(pid32 cbproc, umsg32 msg, uint32 opcode) {
	uint32 rc = send(cbproc, msg);
	uint32 t = clktime;  // there is no clkmilli in fresh copy, thus have to determine by this..

	switch (opcode) {
	case OP_SND_RC:
		send(s_mp, ret_msg(rc));
		break;

	case OP_SND_TIME: {
		//...
		break;
	}

	default:
		break;
	}

	// Again, should not terminate by itself. Or it may mess up with main's msgs.
	while (TRUE) {
		sleepms(SLP_PERIOD);
	}
}


/**
 * Callback function is actually executed.
 */
local int msgcb_executed() {
	send(s_mp, RET_OK);
	return OK;
}


// ==========


/**
 * TC1 - Callback function is really executed when a message comes.
 */
local bool8 cbreg_tc1() {
	bool8 ret = FALSE;
	recvclr(); // clear any previous message due to kill()

	pid32 p2 = create(registercb_proc, INITSTK, INITPRIO+2, "tc1 - p2", 2, msgcb_executed, OP_SND_NONE);
	pid32 p1 = create(p2send_proc, INITSTK, INITPRIO+1, "tc1 - p1", 3, p2, MSG1, OP_SND_NONE);

	resched_cntl(DEFER_START);
	resume(p2); // p2 registers callback function
	resume(p1); // p1 sends to p2
	// then p2 executes again, at which time callback function should be executed
	resched_cntl(DEFER_STOP);

	umsg32 msg = recvtime(1000);
	if (msg == RET_OK) {
		ret = TRUE;
	}
	else {
		kprintf("cbreg_tc1() - callback function is not executed.\n");
	}

	kill(p1);
	kill(p2);
	return ret;
}


process	main(void) {
	kprintf("\n===== Lab 5 Automated Grading =====\n");
	kprintf("\n=== Problem 4 - Asynchronous IPC with CB() check ===\n");
	s_mp = currpid;

	uint32 num_tcs = 5;
	uint32 pts_max[] = { 5, 20, 20, 20, 20 };
	uint32 pts_got[] = { 0, 0, 0, 0, 0 };

	/*
	if (cbreg_tc0()) {
		pts_got[0] = pts_max[0];
		kprintf("cbreg_tc0() passed\n");
	}
	*/

	if (cbreg_tc1()) {
		pts_got[1] = pts_max[1];
		kprintf("cbreg_tc1() passed\n");
	}

	/*
	if (cbreg_tc2()) {
		pts_got[2] = pts_max[2];
		kprintf("cbreg_tc2() passed\n");
	}

	if (cbreg_tc3()) {
		pts_got[3] = pts_max[3];
		kprintf("cbreg_tc3() passed\n");
	}

	if (cbreg_tc4()) {
		pts_got[4] = pts_max[4];
		kprintf("cbreg_tc4() passed\n");
	}
	*/

	kprintf("\n===== Lab 5 Automated Grading completed =====\n");
	kprintf("Problem 4 - Asynchronous IPC with CB() test cases.\n");
	for (int i = 0; i < num_tcs; i++) {
		kprintf("TC %d - %d pts (max: %d)\n", i, pts_got[i], pts_max[i]);
	}
	return OK;
}
