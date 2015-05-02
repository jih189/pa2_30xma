

/* Standard C Library headers use angle brackets <> */
#include <stdlib.h>
/* Library for fprint*/
#include <stdio.h>
/* Library for errno */
#include <errno.h>
/* Library for LONG_MAX/MIN */
#include <limits.h>

/* Local headers use double quotes "" */
#include"pa2.h"
#include"pa2_strings.h"


int main( int argc, char *argv[] ) {

    FILE* inFile;
    int success = parseInput(argv[1], &inFile );

    printf("%d\n", success);


    return EXIT_SUCCESS;
} // end of main()

