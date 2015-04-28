

/*
 * Filename:    creatMask.s
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: SPARC assembly routine to create a mask array.
 * Date:        4/26/2015
 * Sources of Help: None
 */

.global createMask ! Declares the symbol to be globally visible so 
                   ! we can call this function from other modules.
.section ".text"   ! The text segment begins here

TRUE=1
FALSE=0

/*
 * Function name: creatMase
 * Function prototype:
 *      int checkRange( long minRange, long maxRange, long value );
 * Description: The module will check to make sure the value of the third
 *              argument is within the range of minRange and maxRange,
 *              exclusive.
 * Parameters:
 *      arg 1: long minRange -- lower boundary.
 *      arg 2: long maxRange -- higher boundary.
 *      arg 3: long value    -- value to be checked.
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value:
 *      return 0 if value is not in range,
 *      return a non-zero value if in range.
 * Registers Used:
 *      %i0 - arg1 -- minRange
 *      %i1 - arg2 -- maxRange
 *      %i2 - arg3 -- value
 *      %i0 - result.
 */

checkRange:
	save %sp, -96, %sp ! Save caller's window; if different than -96
                           ! then comment on how that value was calculated

lower:
	cmp  %i2, %i0      ! if i2 <= i0, return 0
	ble  exit_false
	nop

upper:
	cmp  %i2, %i1      ! if i2 >= i1, return 0
	bge  exit_false
	nop

exit_true:
	mov  TRUE, %i0     ! in range, return true (1)
	ret
	restore            ! Restore caller's window; in "ret" delay slot

exit_false:
	mov  FALSE, %i0    ! not in range, return false (0)
	ret
	restore            ! Restore caller's window; in "ret" delay slot

