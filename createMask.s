
/*
 * Filename:    createMask.s
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: SPARC assembly to creates two 32-bit mask values.
 * Date:        4/29/2015
 * Sources of Help: None
 */

	.global createMask 
	.section ".text"

LONG_SIZE=32
ARRAY_OFFSET=4

/*
 * Function name: createmask
 * Function prototype:
 *      void createMask( unsigned long keys[], char passphrase[], unsigned long mask[] );
 * Description:
 * Parameters:
 *      arg1: unsigned long mask[] -- the mask to be rotate
 *      arg2: char passphrase[] -- the passphrase to XOR with
 *      arg3: unsigned long mask[] -- store the result
 * Side Effects:
 *      It will set mask[]
 * Error Conditions: none
 * Return Value: none
 * Registers Used:
 *      %i0 - arg1 -- address of the first array element
 *      %i1 - arg2 -- rotateCnt
 *      %i2 - arg3 -- mask[]
 *      %l0 -- first element of array,   mask[0]
 *      %l1 -- second element of array,  mask[1]
 */

rotate:
	save %sp, -96,  %sp ! Save caller's window;

        ! only use the last 6 bits of rotateCnt
        ! then the rotate direction won't matter
	andcc %i1, LAST_6_BIT_MASK, %i1
	be return                     ! if rotateCnt == 0, simply return
	nop

	ld [%i0],%l0                  ! save mask[0] into %l0
	ld [%i0 + ARRAY_OFFSET], %l1  ! save mask[1] into %l1

check_ge_32:
	cmp %i1, LONG_SIZE            ! (rotateCnt >= LONG_SIZE)?
	bl  shift_left
	nop

swap:
        ! swap mask0 and mask1
	mov %l0, %l6                  ! temp = mask[0]
	mov %l1, %l0                  ! mask[0] = mask[1]
	mov %l6, %l1                  ! mask[1] = temp

	subcc %i1, LONG_SIZE, %i1     ! rotateCnt -= LONG_SIZE
	be return                     ! if new rotateCnt == 0, simply return
	nop

shift_left:
	! save parts get shifted off: off0 & off1
	mov LONG_SIZE, %l5
	sub %l5, %i1, %l5        ! %l5 = 32 - rotateCnt

	srl %l0, %l5, %l2        ! %l2 = off0 = mask0 >> (32-n)
	srl %l1, %l5, %l3        ! %l3 = off1 = mask1 >> (32-n)

        ! shift mask0 and mask1 to the left by rotateCnt
	sll %l0, %i1, %l0
	sll %l1, %i1, %l1

	! combine the new masks and the shifted-off parts
	! NOTICE off0 will be the lower part of mask1 after correct
	! rotation and off1 of mask0

	or  %l0, %l3, %l0        ! combine mask0 and off1
	or  %l1, %l2, %l1        ! combine mask1 and off0

	! done, update (unsigned long*)mask
	st %l0, [%i0]                ! put modified mask[0] value back
	st %l1, [%i0 + ARRAY_OFFSET] ! put modified mask[1] value back

return:
	ret
	restore

