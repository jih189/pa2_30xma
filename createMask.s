
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

ARRAY_OFFSET=4

/*
 * Function name: createMask
 * Function prototype:
 *      void createMask( unsigned long keys[], char passphrase[], unsigned long mask[] );
 * Description:
 * Parameters:
 *      arg1: unsigned long keys[] -- the keys to be XOR
 *      arg2: char passphrase[] -- the passphrase to XOR with
 *      arg3: unsigned long mask[] -- store the result
 * Side Effects:
 *      It will create mask[] using keys[] and passphrase[]
 * Error Conditions: none
 * Return Value: none
 * Registers Used:
 *      %i0 - arg1 -- address of the first element in keys[]
 *      %i1 - arg2 -- address of the first element in passphrase[]
 *      %i2 - arg3 -- place to hold mask[] 
 *      %l0 -- key[0]  
 *      %l1 -- key[1]  
 *      %l2 -- passphrase[0-3]
 *      %l3 -- passphrase[4-7]
 */

createMask:
	save %sp, -96,  %sp ! Save caller's window;

	ld [%i0],%l0                  ! %l0 = key[0]
	ld [%i0 + ARRAY_OFFSET], %l1  ! %l1 = key[1]

	ld [%i1], %l2                 ! %l2 = passphrase[0-3]  
	ld [%i1 + ARRAY_OFFSET], %l3  ! %l3 = passphrase[4-7]  
	
	xor %l0, %l2, %l4             ! %l4 = key[0] ^ passphrase[0-3]
	xor %l1, %l3, %l5             ! %l5 = key[1] ^ passphrase[4-7]

	! done, update (unsigned long*)mask
	st %l4, [%i2]                 ! mask[0] = key[0] ^ passphrase[0-3]
	st %l5, [%i2 + ARRAY_OFFSET]  ! mask[1] = key[1] ^ passphrase[4-7]
return:
	ret
	restore

