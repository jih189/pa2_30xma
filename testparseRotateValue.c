
/*
 * Unit Test for rotate.s
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
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"        /* For parseRotateValue function prototype */

void
testparseRotateValue()
{

    printf( "Testing parseRotateValue\n" );

    /*
     * Test with rotateCnt of 0 - should be no change.
     */

    char *testString = "99abc";
    long rotateValue = 0; 

    int errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);

    TEST( errFlag  == ENDPTR_ERR  );
    
    /*
     *
     */

    testString = "999999999999999999";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);
    TEST( errFlag  == ERANGE_ERR  );

    /*
     *
     */

    testString = "20";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);
    TEST( errFlag  == 0  );

    /*
     *
     */

    testString = "70";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);
    TEST( errFlag  == BOUND_ERR  );

    /*
     *
     */

    testString = "-70";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);
    TEST( errFlag  == BOUND_ERR);

    /*
     *
     */

    testString = MIN_ROTATE_STR;
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);
    TEST( errFlag  == 0 );


    printf( "Finished running tests on parseRotateValue()\n" );

    /*
     *
     */

    testString = MAX_ROTATE_STR;
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    printf("return value is %d,testInt is %d \n", errFlag, rotateValue);
    TEST( errFlag  == 0 );


    printf( "Finished running tests on parseRotateValue()\n" );
}

int
main()
{
    testparseRotateValue();

    return 0;
}

