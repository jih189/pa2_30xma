

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


int main() {

    char *src = "abcdefgh";
    char des[PASS_PHRASE_SIZE];

    int errorCheck = parsePassPhrase(src,des);

    printf("%d\n", errorCheck);
    printf("%s\n",des);


    return EXIT_SUCCESS;
} // end of main()

