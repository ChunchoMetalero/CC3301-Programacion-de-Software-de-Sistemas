	.file	"sort-c-wc.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	strCmp
	.type	strCmp, @function
strCmp:
	lbu	a5,0(a0)
	lbu	a4,0(a1)
	beq	a5,zero,.L2
.L3:
	bne	a5,a4,.L2
	addi	a0,a0,1
	addi	a1,a1,1
	lbu	a5,0(a0)
	lbu	a4,0(a1)
	bne	a5,zero,.L3
.L2:
	sub	a0,a5,a4
	ret
	.size	strCmp, .-strCmp
	.align	2
	.globl	countWords
	.type	countWords, @function
countWords:
	mv	a3,a0
	lbu	a4,0(a0)
	beq	a4,zero,.L14
	li	a5,0
	li	a0,0
	li	a2,32
	j	.L12
.L7:
	addi	a0,a0,1
	add	a4,a3,a5
	lbu	a4,0(a4)
	beq	a4,a2,.L10
.L9:
	beq	a4,zero,.L8
	addi	a5,a5,1
	add	a4,a3,a5
	lbu	a4,0(a4)
	bne	a4,a2,.L9
.L10:
	add	a4,a3,a5
	lbu	a4,0(a4)
	j	.L12
.L8:
	add	a4,a3,a5
	lbu	a4,0(a4)
	beq	a4,zero,.L16
.L12:
	bne	a4,a2,.L7
	addi	a5,a5,1
	j	.L8
.L16:
	ret
.L14:
	li	a0,0
	ret
	.size	countWords, .-countWords
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	sw	s1,20(sp)
	sw	s2,16(sp)
	sw	s3,12(sp)
	sw	s4,8(sp)
	sw	s5,4(sp)
	slli	s4,a1,2
	addi	s4,s4,-4
	add	s4,a0,s4
	bgeu	a0,s4,.L17
	mv	s5,a0
	mv	s0,a0
	j	.L21
.L19:
	sw	s3,0(s0)
	sw	s2,4(s0)
	mv	s0,s5
.L21:
	lw	s2,0(s0)
	mv	a0,s2
	call	countWords
	mv	s1,a0
	lw	s3,4(s0)
	mv	a0,s3
	call	countWords
	bgt	s1,a0,.L19
	addi	s0,s0,4
	bgtu	s4,s0,.L21
.L17:
	lw	ra,28(sp)
	lw	s0,24(sp)
	lw	s1,20(sp)
	lw	s2,16(sp)
	lw	s3,12(sp)
	lw	s4,8(sp)
	lw	s5,4(sp)
	addi	sp,sp,32
	jr	ra
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
