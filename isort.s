/*
 * assembly file isort.s for isort() function, extra credit for 
 * CSE 30 PA2 - mycrypt.
 *
 * Performs an insertion sort.
 */

	.section	".text"
	.global isort

isort:
	save	%sp, -96, %sp

	mov	1, %l0

	cmp	%l0, %i1
	bge	endarray
	nop

startarray:

	mov	%l0, %l1

	cmp	%l1, %g0
	ble	endinner
	nop

startinner:

	mov	%l1, %o0
	mov	4, %o1
	call	.mul
	nop

	mov	%o0, %l2
	add	%i0, %l2, %l2
	ld	[%l2], %l3
	ld	[%l2 - 4], %l4

	cmp	%l3, %l4
	bge	endinner
	nop

	st	%l4, [%l2]
	st	%l3, [%l2 - 4]

	add	%l1, -1, %l1

	cmp	%l1, %g0
	bg	startinner
	nop

endinner:

	add	%l0, 1, %l0

	cmp	%l0, %i1
	bl	startarray
	nop

endarray:

	add	%i1, -1, %l0
	sll	%l0, 2, %l0
	add	%i0, %l0, %l0
	ld	[%l0], %l0

	ld	[%i0], %i0
	sub	%l0, %i0, %i0

	ret
	restore
