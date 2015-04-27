
/*
 * Filename:    parseKey.c
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: C routine to convert a string to a unsigned long.
 * Date:        4/26/2015
 * Sources of Help: none 
 */

#include <stdio.h>
#include <stdlib.h>
/* Library for errno */
#include <errno.h>
/* Library for LONG_MAX/MIN */
#include <limits.h>
#include "pa2_strings.h"
#include "pa2.h"

/*
 * Function name: parseKey
 * Function prototype:  int parseKey( char *str, unsigned long *key )
 * Description: 
 *        This module is responsible for parsing either of the key values.
 * Parameters:
 *        arg1: char *str -- the string to be converted
 *        arg2: unsigned long *key -- the unsigned long to store value.
 * Side Effects: it will set key.
 * Error Conditions: Checks if argl1 is valid string of interger.
 * Return Value: 
 *        0 -- if the string is parsed successfully.
 *        ENDPTR_ERR(1) -- if endptr points to a non-null character.
 *        ERANGE_ERR(2) -- if errno is set to non-zero.
 */

int parseKey( char *str, unsigned long *key ) {

  char *pEnd;
  errno = 0;
  *key = strtoul( str, &pEnd, DEF_BASE );
  if (
      errno == ERANGE && (*key == ULONG_MAX || *key == LONG_MIN)
      || (errno != 0 && *key == -1)
      ) {
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

}
