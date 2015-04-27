
/*
 * Unit Test for parseKey
 *
 * void rotate( unsigned int mask[], int rotateCnt );
 *
 * Takes mask[0] as high order 32 bits and mask[1] as low order 32 bits
 * and simulates a 64-bit rotate within these two words.
 *
 * Lower 6 bits of rotateCnt is masked to keep rotate range 0-63.
 *
 * Positive rotateCnt - rotate left
 * Negative rotateCnt - rotate right
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <stdio.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For rotate() function prototype */

int
main()
{

    char *testString1 = "99abc";
    unsigned long testInt1; 

    int returnValue1 = parseKey(testString1, &testInt1 );

//     if (!testInt1) printf( "nullptr\n" );
//     else
    printf("return value is %d,testInt is %d \n", returnValue1, testInt1);
    
    char *testString2 = "999999999999999999";
    unsigned long testInt2; 

    int returnValue2 = parseKey(testString2, &testInt2 );

//     if (!testInt2) printf( "nullptr\n" );
//     else
    printf("return value is %d,testInt is %d \n", returnValue2, testInt2);
   
    return 0;
}

