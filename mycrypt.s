
/*
 * Filename:    mycrypt.s
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: SPARC assembly routine to encrypt/decrypt file
 * Date:        5/4/2015
 * Sources of Help: None
 */

	.global mycrypt
	.section ".text"

BUFSIZE=1024
CHUNKSIZE=8
LONG_OFFSET=4

/*
 * Function name: mycrypt
 * Function prototype:
 *      void mycrypt( FILE *inFile, unsigned long mask[], int rotateValue );
 * Description:
 * 	This function encrypt a file using given mask.
 * Parameters:
 *      arg1: inFile -- the File* point to a file need to be read
 *      arg2: mask   -- the mask used to encrypt
 *      arg3: rotateValue -- rotateValue after each 8 byte encrypt
 * Side Effects: none
 * Error Conditions: none
 * Return Value: none
 * Registers Used:
 *    %i0 - arg1 -- inFile 
 *    %i1 - arg2 -- mask   
 *    %i2 - arg3 -- rotateValue
 *    %l0 - hold starting pos of data needed to encrypt,keep decreasing
 *    %l1 - save how many characters have read in BUFFER[1024]
 *    %l2 - updated remained byte to modify, keep decreasing
 */

mycrypt:
	save %sp, -(92 + BUFSIZE) & -8,  %sp ! Save caller's window;

        ! first time read BUFSIZE(1024) byte

	add %fp,-BUFSIZE, %l0         ! %l0 save the local ptr initial location
	mov %l0, %o0                  ! move local buffer ptr as arg 1 of fread
	mov 1, %o1                    ! read 1 byte each time for fread
	mov BUFSIZE, %o2              ! read BUFSIZE(1024) byte total
	mov %i0, %o3                  ! pass FILE* inFile to fread as arg3
	call fread                    
	nop

outer_loop:
	cmp %o0, 0                    ! check if read data successfully
	be end_outer_loop             ! fread not read any data, return
	nop

outer_loop_body:

chunck_rotate_loop:
	mov %o0, %l1                  ! %l1 = actual byte read each time 
	mov %l1, %l2                  ! %l2 = cp %l1, keep decreasing 

	cmp %l2, CHUNKSIZE            ! byte read >= 8?
	bl  end_chunck_rotate         ! read < 8, modify byte by byte
	nop

chunck_rotate_body:
	ld [%l0], %l3                 ! %l3 = first 4 byte
	ld [%i1], %l4                 ! %l4 =  mask[0]
	xor %l3, %l4, %l4             ! first 4 byte ^ mask[0]
	st  %l4, [%l0]                ! store first 4 byte back to buffer ptr
	                              ! %l0 points to chunck starting address

	ld [%l0+LONG_OFFSET], %l3     ! %l3 = second 4 byte
	ld [%i1+LONG_OFFSET], %l4     ! %l4 = mask[1]
	xor %l3, %l4, %l4             ! second 4 byte ^ mask[1]
	st %l4, [%l0+LONG_OFFSET]     ! store second 4 byte back 

	mov %i1, %o0                  ! arg1 = mask to be rotate
	mov %i2, %o1                  ! arg2 = rotateValue 
	call rotate
	nop
	
	add  %l0, CHUNKSIZE, %l0      ! update chunck start pos, 
	sub  %l2, CHUNKSIZE, %l2      ! update byte remained value
	cmp  %l2, CHUNKSIZE           ! Remained byte > CHUNKSIZE(8)?
	bge  chunck_rotate_body
	nop

end_chunck_rotate:

byte_rotate_loop:
	clr %l3                      ! local counter for byte read
	cmp %l2, 0                   ! Remained byte > 0?
	be  end_byte_rotate
	nop

byte_rotate_body:
	ldub [%l0 + %l3], %l4        ! get remained first byte
	ldub [%i1 + %l3], %l5        ! get mask first byte
	xor   %l4, %l5, %l5
	stb  %l5, [%l0+%l3]          ! store back updated byte value

	inc %l3                      ! update byte read counter
	dec %l2                      ! update byte remained value
	cmp %l2, 0                   ! remained byte > 0?
	bg  byte_rotate_body
	nop

end_byte_rotate:

	set standardOut, %l3          ! %l3 = &standardOut
	ld [%l3], %l3                 ! get global var standardOut

        ! write first 1024 byte to stdout

	add %fp, -BUFSIZE, %o0        ! pass local buffer ptr 
	mov 1, %o1                    ! write 1 byte at a time
	mov %l1, %o2                  ! write the same amount of byte as read 
	mov %l3, %o3                  ! stdout to arg 4
	call fwrite                   !
	nop

        ! read another BUFSIZE(1024) byte

	add %fp, -BUFSIZE, %l0        ! pass local buffer ptr
	mov %l0, %o0                  ! move local buffer ptr as arg 1 of fread
	                              ! 1 already in %o1
	mov BUFSIZE, %o2              ! read BUFSIZE(1024) byte total
	mov %i0, %o3                  ! pass FILE* inFile to fread as arg3
	call fread
	nop

	cmp %o0, 0                    ! check if data read successfully
	bg outer_loop_body
	nop

end_outer_loop:
	ret
	restore

