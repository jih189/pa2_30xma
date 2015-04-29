
/*
 * Unit Test for parseRotateValue.s
 *
 * int parseRotateValue( char *str, long *rotateValue  );
 *
 * This module is responsible for parsing the rotation value.
 *
 * Return value:
 * 0 -- if the string is parsed successfully.
 * ENDPTR_ERR(1) -- if contains characters.
 * ERANGE_ERR(2) -- if string is out of the size of long
 * BOUND_ERR(3)  -- if string out of bound [-63, 63]
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"        /* For parseRotateValue function prototype */

void
testparseRotateValue()
{
    char *testString;
    long rotateValue; 
    int errFlag;

    printf( "Testing parseRotateValue\n" );

    /*
     * Test with string contains characters
     */

    testString = "99abc";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == ENDPTR_ERR  );
    
    /*
     * Test with string out of bound of long
     */

    testString = "999999999999999999";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == ERANGE_ERR  );

    /*
     * Test normal case
     */

    testString = "20";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == EXIT_SUCCESS && rotateValue == 20 );

    /*
     * Test string to be parsed out of upper setting bound [-63, 63]
     */

    testString = "70";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == BOUND_ERR && rotateValue == 0 );

    /*
     * Test string to be parsed out of lower setting bound [-63, 63]
     */

    testString = "-70";
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == BOUND_ERR && rotateValue == 0);

    /*
     * Test with MIN_ROTATE (-63)
     */

    testString = MIN_ROTATE_STR;
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == EXIT_SUCCESS && rotateValue == MIN_ROTATE);


    /*
     * Test with MAX_ROTATE (63)
     */

    testString = MAX_ROTATE_STR;
    rotateValue = 0; 

    errFlag = parseRotateValue(testString, &rotateValue );

    TEST( errFlag  == EXIT_SUCCESS && rotateValue == MAX_ROTATE);


    printf( "Finished running tests on parseRotateValue()\n" );
}

int
main()
{
    testparseRotateValue();

    return 0;
}

