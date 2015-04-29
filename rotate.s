
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
 *      %i0 - arg1 -- 
 *      %i1 - arg2 -- 
 *      %i2 - arg3 -- 
 */

 //      void rotate( usigned long mask[], int rotateCnt );
 // 	If the rotateCnt is positive, rotate left; 
 // 	if the rotateCnt is negative, rotate right. 
 // 	Only the lower 6 bits of the rotateCnt should be used for the rotateCnt.

rotate:
	save %sp, -(92 + ENDPTR_OFFSET) & -8, %sp 
                           ! Save caller's window; 
                           ! store char endPtr on the statck
get_6bit_cnt:
			
	cmp %i1, 0         ! if (rotateCnt >= 0)
	bl  rotaeRight     ! if rotateCnt is neg, rotate right
	nop

rotateLeft:
				
rotateRight:

get_pos_cnt:


if (rotateCnt >= 0) {
// loop
// rotate left
} else {
// loop
// rotate right
}
