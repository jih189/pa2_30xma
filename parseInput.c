
/*
 * Filename:    parseInput.c
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: C routine to parsing the specified input file
 * Date:        5/1/2015
 * Sources of Help: none 
 */

#include <stdio.h>
#include <stdlib.h>
/* Library for strcmp */
#include <string.h>
/* Library for errno */
#include <errno.h>
/* Library for LONG_MAX/MIN */
#include <limits.h>
#include "pa2_strings.h"
#include "pa2.h"

/*
 * Function name: parseInput
 * Function prototype: int parseInput( char *str, FILE **inFile );
 * Description: 
 *        This module is responsible for parsing the specified input file.
 *        if the str contains just dash "-", inFile will be set to stdin, 
 *        otherwise, str is the name of a file to be opened.
 * Parameters:
 *        arg1: char *str -- the string to be parsed
 *        arg2: FILE ** inFile -- The file to be opend.
 * Side Effects: t will set inFile 
 * Error Conditions: none
 * Return Value: 
 *        0 -- if the string is parsed successfully.
 *        FILE_ERR(4) -- if the file not opened successfully
 */

int parseInput( char *str, FILE **inFile ){

  errno = 0;
  // strcmp return 0 if equal
  int isStdin = ! (strcmp (str, "-"));

  if (isStdin) *inFile = stdin;
  // open the file, check if opens successfully, set inFile to the return
  // FILE ptr
  else {
    // open file with name str , in read mode
    *inFile = fopen(str, FILE_OPEN_OPT);
    if (errno) {
      return FILE_ERR;
    }
  }
  return EXIT_SUCCESS;
}
