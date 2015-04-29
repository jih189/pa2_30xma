
/*
 * Filename:    rotate.s
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: SPARC assembly routine to to rotate a 64-bit mask by rotateCnt
 *              places.
 *              called from mycrypt.s
 * Date:        4/27/2015
 * Sources of Help: None
 */

	.global rotate
	.section ".text"   

LAST_6_BIT_MASK=0x3F
LONG_SIZE=32
ARRAY_OFFSET=4
/*
 * Function name: rotate
 * Function prototype:
 *      void rotate( usigned long mask[], int rotateCnt );
 * Description: 
 * 	This function rotates the current 64-bit mask (mask[] ) by rotateCnt
 * 	places. 
 * 	If the rotateCnt is positive, rotate left; 
 * 	if the rotateCnt is negative, rotate right. 
 * 	Only the lower 6 bits of the rotateCnt should be used for the rotateCnt.
 *      But since we only use the lower 6 bits, thus shift right
 * Parameters:
 *      arg1: unsigned long mask[] -- the mask to be rotate
 *      arg2: rotateCnt -- the amount of times we are rotateing and the
 *            direction
 * Side Effects: 
 *      It will set rotateValue
 * Error Conditions: 
 *      Checks if argl1 is valid string of interger.
 * Return Value:
 *      0 -- if the string is parsed successfully.
 *      ENDPTR_ERR(1) -- if endptr points to a non-null character.
 *      ERANGE_ERR(2) -- if errno is set to non-zero.
 * Registers Used:
 *      %i0 - arg1 -- address of the first array element
 *      %i1 - arg2 -- rotateCnt
 *      %l0 -- first element of array,   mask[0]
 *      %l1 -- second element of array,  mask[1]
 */

rotate:
	save %sp, -96  %sp 
                           ! Save caller's window; 
                           ! store char endPtr on the statck

	and %i1, LAST_6_BIT_MASK, %i1  ! only use the last 6 bits of rotateCnt
	                               ! then the rotate direction won't matter 

	ld [%i0],%l0       ! save mask[0] into %l0
	ld [%l0 + ARRAY_OFFSET], %l1  ! save mask[1] into %l1

check_ge_32:
	cmp %i1, LONG_SIZE ! (rotateCnt >= 32)?
	bl  shift_left      
	nop

swap:
	mov %l0, %l6       ! temp = mask[0] 
	mov %l1, %l0       ! mask[0] = mask[1]
	mov %l6, %l1       ! mask[1] = temp
	
	sub LONG_SIZE, %i1, %i1 ! rotateCnt = (32 - rotateCnt)


shift_left:
	sll %l0, %i1, %l2        !a' in %l2
	sll %l1, %i1, %l3        !b' in %l3

	sub LONG_SIZE, %i1, %i1  !(32 - rotateCnt) in %i1

	srl %l0, %i1, %l0        ! c in %l0
	srl %l1, %i1, %l1        ! d in %l1

	or  %l2, %l1, %l0        ! mask[0] after shift is in %l0
	or  %l3, %l0, %l1        ! mask[1] after shift is in %l0

	st %l0, [%i0]            ! put modified mask[0] value back
	st %l1, [$l0 + ARRAY_OFFSET] ! put modified mask[1] value back

	ret
	restore


