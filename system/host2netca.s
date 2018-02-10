	.file	"host2netca.c"
	.text
	.globl	host2netca
	.type	host2netca, @function
host2netca:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	sall	$24, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	andl	$65280, %eax
	sall	$8, %eax
	orl	%eax, %edx
	movl	8(%ebp), %eax
	andl	$16711680, %eax
	sarl	$8, %eax
	orl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	shrl	$24, %eax
	orl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	host2netca, .-host2netca
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.6) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
