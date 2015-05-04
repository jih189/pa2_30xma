
/*
 * Filename:    mycrypt.s
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: SPARC assembly routine to to rotate a 64-bit mask by rotateCnt
 *              places.
 *              called from mycrypt.s
 * Date:        4/27/2015
 * Sources of Help: None
 */

	.global mycrypt
	.section ".text"
BUFSIZE=1024
ARRAY_OFFSET=4
/*
 * Function name: mycrypt
 * Function prototype:
 *      void mycrypt( FILE *inFile, unsigned long mask[], int rotateValue );
 * Description:
 * 	This function encrypt a file using given mask.
 * Parameters:
 *      arg1: inFile -- the File * point to a file need to be read
 *      arg2: mask   -- the mask used to encrypt
 *      arg3: rotateValue -- rotateValue after each 8 byte encrypt
 * Side Effects: none
 * Error Conditions: none
 * Return Value: none
 * Registers Used:
 *      %i0 - arg1 -- inFile 
 *      %i1 - arg2 -- mask   
 *      %i2 - arg3 -- rotateValue
 *      %l0 -- first element of array,   mask[0]
 *      %l1 -- second element of array,  mask[1]
 */

 // void mycrypt( FILE *inFile, unsigned long mask[], int rotateValue );
mycrypt:
	save %sp, -(92 + BUFSIZE) & -8,  %sp ! Save caller's window;


	call fread                    ! call fread
	cmp %o0 0
	be END_OF_FILE
	nop

	ld [%i0],%l0                  ! save mask[0] into %l0
	ld [%i0 + ARRAY_OFFSET], %l1  ! save mask[1] into %l1


END_OF_FILE:
	ret
	restore

