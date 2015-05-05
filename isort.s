/*
 * assembly file isort.s for isort() function, extra credit for 
 * CSE 30 PA2 - mycrypt.
 *
 * Performs an insertion sort.
 * name: Liu Tan
 * id: cs30xma
 * date: May 4, 2015
 */

	.section	".text"
	.global isort

isort:
	save	%sp, -96, %sp

	mov	1, %l0

	cmp	%l0, %i1
	bge,a	endarray       ! #2 nop
	add	%i1, -1, %l0   ! #2 nop, 1st line after endarray

startarray:

	mov	%l0, %l1

	cmp	%l1, %g0
	ble,a	endinner       ! #3 nop
	add	%l0, 1, %l0    ! #3 nop, 1st line after endinner

startinner:

	mov	4, %o1
	call	.mul
	mov	%l1, %o0    ! first nop, mov replace nop

	mov	%o0, %l2
	add	%i0, %l2, %l2
	ld	[%l2], %l3
	ld	[%l2 - 4], %l4

	cmp	%l3, %l4
	bge,a	endinner
	add	%l0, 1, %l0    ! #3 nop, 1st line after endinner

	st	%l4, [%l2]
	st	%l3, [%l2 - 4]

	add	%l1, -1, %l1

	cmp	%l1, %g0
	bg	startinner
	nop

	add	%l0, 1, %l0    ! #3 nop, 1st line after endinner

endinner:

	cmp	%l0, %i1
	bl	startarray
	nop

	add	%i1, -1, %l0   ! #2 nop, 1st line after endarray

endarray:

	sll	%l0, 2, %l0
	add	%i0, %l0, %l0
	ld	[%l0], %l0    !%l0 = max

	ld	[%i0], %i0    !%i0 = min
	sub	%l0, %i0, %i0

	ret
	restore
