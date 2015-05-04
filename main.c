
/*
 * Filename:    main.c
 * Author:      Liu Tan
 * Userid:      cs30wma
 * Description: Example C program for pa1. It calls a couple of functions
 *              written in assembly and C as examples of function calls and
 *              parameter passing in C and SPARC assembly (also known as
 *              the language's and architecture's calling conventions)
 * Date:        4/17/2015
 * Sources of Help: None 
 */

/* Standard C Library headers use angle brackets <> */
#include <stdlib.h>
/* Library for fprint*/
#include <stdio.h>
/* Library for strlen*/
#include <string.h>
/* Library for errno */
#include <errno.h>
/* Library for LONG_MAX/MIN */
#include <limits.h>

/* Local headers use double quotes "" */
#include"pa2.h"
#include"pa2_strings.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: 
 *    This module is responsible for driving the program. It will properly
 *    parse all of the command line arguments, create the  mask, perform the
 *    encryption/decryption, and close the file.
 * Parameters:  
 * Side Effects: none
 * Error Conditions: None.
 * Return value: 0 indicating successful execution.
 */

int main( int argc, char *argv[] ) {

  // disable buffering on stdout
  (void) setvbuf( stdout, NULL, _IONBF, 0 );

    argc--;
    // check if the correct number of arguments is given

    if ( argc != EXPECTED_ARGS) {

        /* Error messages are printed to stderr */
        (void) fprintf ( stderr, STR_USAGE, 
                          argv[0],  // .exe name
                          MIN_ROTATE, // Lower bound of rotatevalue
                          MAX_ROTATE  // upper bound of rotatevalue
                          );  
        return EXIT_FAILURE;
    }

    int errCheck = 0;
    int errNum = 0;
    char* passphrase = "";
    unsigned long keys[] = {0,0};
    long rotateValue = 0;
    FILE* infile = NULL;

    // ----------------------------------------------------------------------
    // parse passphrase
    errCheck = parsePassPhrase(argv[PASS_PHRASE_INDEX], passphrase);
    if (errCheck == LENGTH_ERR) {
        fprintf ( stderr, STR_ERR_BAD_PASSPHRASE, argv[1] );
        errNum += errNum;
    }

    // ----------------------------------------------------------------------
    // parseKey 1
    errCheck = parseKey(argv[KEY_ONE_INDEX], keys);
    if (errCheck == ERANGE_ERR) {
      char err_buffer[ERR_BUFFER_SIZE];
      snprintf(err_buffer,ERR_BUFFER_SIZE,STR_ERR_CONVERTING,
          argv[KEY_ONE_INDEX],DEF_BASE);
      perror(err_buffer);
      errNum += errNum;
    } else if (errCheck == ENDPTR_ERR) {
      fprintf ( stderr, STR_ERR_NOTINT, argv[KEY_ONE_INDEX]);
      errNum += errNum;
    }

    // parseKey 2
    errCheck = parseKey(argv[KEY_TWO_INDEX], &keys[1]);
    if (errCheck == ERANGE_ERR) {
      char err_buffer[ERR_BUFFER_SIZE];
      snprintf(err_buffer,ERR_BUFFER_SIZE,STR_ERR_CONVERTING,
          argv[KEY_TWO_INDEX],DEF_BASE);
      perror(err_buffer);
      errNum += errNum;
    } else if (errCheck == ENDPTR_ERR) {
      fprintf ( stderr, STR_ERR_NOTINT, argv[KEY_TWO_INDEX]);
      errNum += errNum;
    }

    // parseRotateValue
    // ----------------------------------------------------------------------
    errCheck = parseRotateValue(argv[ROTATE_VALUE_INDEX], &rotateValue);
    if (errCheck == ERANGE_ERR) {
      char err_buffer[ERR_BUFFER_SIZE];
      snprintf(err_buffer,ERR_BUFFER_SIZE,STR_ERR_CONVERTING,
          argv[ROTATE_VALUE_INDEX],DEF_BASE);
      perror(err_buffer);
      errNum += errNum;
    } else if (errCheck == ENDPTR_ERR) {
      fprintf ( stderr, STR_ERR_NOTINT, argv[ROTATE_VALUE_INDEX]);
      errNum += errNum;
    } else if (errCheck == BOUND_ERR) {
      fprintf ( stderr, STR_ERR_BAD_ROT, MIN_ROTATE, MAX_ROTATE );
      errNum += errNum;
    }

    // parseInput
    // ----------------------------------------------------------------------
    errCheck = parseInput(argv[FILE_INDEX], &infile);
    if (errCheck == FILE_ERR) { 
      fprintf ( stderr, STR_ERR_BAD_FILE, infile);
      errNum += errNum;
    }

    // check if any error occured
    if (errNum)
    fprintf( stderr, STR_ERR_NUM_ERRORS, errNum);

    //mycrypt (FILE *inFile, unsigned long mask[], int rotateValue);

    return EXIT_SUCCESS;
} // end of main()


