
/*
 * Filename:    checkRange.s
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: SPARC assembly routine to to convert a string to a unsigned
 *              long.  
 * Date:        4/26/2015
 * Sources of Help: None
 */


.global parseRotateValue.s 
.section ".text"   

BASE=10;
ENDPTR_OFFSET=4

/*
 * Function name: parseRotateValue 
 * Function prototype:
 *      int parseRotateValue( char *str, long *rotateValue  );
 * Description: 
 *      This module is responsible for parsing the rotation value.
 * Parameters:
 *      arg1: char *str -- the string to be converted
 *      arg2: long *rotateValue -- the long to store value.
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
 *      %i0 - result.
 */

/*
int parserotateValue( char *str, unsigned long *rotateValue ) {

  char *pEnd;
  errno = 0;
  *rotateValue = strtol( str, &pEnd, DEF_BASE );
  if ( (errno != 0 ) {
      char err_buffer[ERR_BUFFER_SIZE];
      snprintf(err_buffer,ERR_BUFFER_SIZE,STR_ERR_CONVERTING,str,DEF_BASE);
      perror(err_buffer);
      errno = 0;
      return ERANGE_ERR;
  } else if (*pEnd != NULL) {
    fprintf ( stderr, STR_ERR_NOTINT, str);
    return ENDPTR_ERR;
  }

  return EXIT_SUCCESS;

*/

parseRotateValue:
	save %sp, -(92 + ENDPTR_OFFSET) & -8, %sp 
                           ! Save caller's window; 
                           ! store char endPtr on the statck

	set errno, %l0     ! address of where we can find errno storage
	st  %g0,  [%l0]    ! dereference to set errno = 0

	mov %i0, %o0       ! pass str to strtol arg1
	add %fp, -ENDPTR_OFFSET, %o1 ! pass &endPtr to strtol arg2
	mov BASE %o2       ! pass BASE(10) to strtol arg3
	call strtol        
	nop

	st %o0, [%i1]      ! store the return of strtol to *rotateValue

checkErrno:
	set errno, %l0     ! load address of errno
	ld  [%l0], %l0     ! get the value of errno
	cmp %l0, %g0       ! check if (errno != 0), if so, report erro
	bne errnoError
	nop

checkEndptr:
        ld   [%fp - ENDPTR_OFFSET], %l1 ! get the value of endPtr
	ldub [%l1], %l1                 ! dereference endptr to get the char
	cmp  %l1, %g0       ! check if (*endptr!= '\0')
	bne  endptrError
	nop

checkRange:
	

Exit_Norm:
        mov  0, %i0  ! return 0 if parse successfully
	ret          ! return from subroutine
	restore      ! Restore caller's window; in "ret" delay slot

errnoError:
	set ERANGE_ERR_G, %l0
	ld  [%l0], %li       ! save value in ENDPTR_ERRA(1) as return value
	ret
	restore

endptrError:
	set ENDPTR_ERR_G, %l0
	ld  [%l0], %li       ! save value in ENDPTR_ERRA(1) as return value
	ret
	restore










 






