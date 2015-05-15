
/*
 * Filename:    parsePassPhrase.c
 * Author:      Liu Tan
 * Userid:      cs30xma
 * Description: C routine to convert a string to a string.
 * Date:        5/1/2015
 * Sources of Help: none 
 */

#include <stdio.h>
#include <stdlib.h>
/* Library for strlen*/
#include <string.h>
/* Library for errno */
#include <errno.h>
/* Library for LONG_MAX/MIN */
#include <limits.h>
#include "pa2_strings.h"
#include "pa2.h"

/*
 * Function name: parsePassPhrase
 * Function prototype:  int parsePassPhrase( char *str, char *passphrase );
 * Description: 
 *        This module is responsible for parsing the passphrase
 * Parameters:
 *        arg1: char *str -- the string to be converted
 *        arg2: char *passphrase -- the char ptr to store value.
 * Side Effects: it will set passphrase
 * Error Conditions: 
 * Return Value: 
 *        EXIT_SUCCESS(0) -- if the string is parsed successfully.
 *        LENGTH_ERR(5)   -- string is too short
 */

int parsePassPhrase( char *str, char *passphrase ) {

  int size = strlen(str);

  if (size < PASS_PHRASE_SIZE) return LENGTH_ERR;

  (void)strncpy(passphrase, str, PASS_PHRASE_SIZE);

  passphrase[PASS_PHRASE_SIZE] = '\0';

  return EXIT_SUCCESS;

}

