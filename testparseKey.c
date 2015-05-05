
/*
 * Unit Test for parseKey
 *
 * int parseKey( char *str, unsigned long *key )
 *
 * This function convert a string to a unsigned long.
 *
 * Return Value: 
 *        0 -- if the string is parsed successfully.
 *        ENDPTR_ERR(1) -- if string contains characters
 *        ERANGE_ERR(2) -- if string is out of bound
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <stdio.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For rotate() function prototype */

void
testparseKey()
{

    char *testString;
    unsigned long testInt; 
    int returnValue; 

//  Test string with character
//  --------------------------------------------------

    testString = "99abc";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

    TEST( returnValue == ENDPTR_ERR );

    
//  Test string out of range.
//  --------------------------------------------------

    testString = "999999999999999999";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

    TEST( returnValue == ERANGE_ERR );


//  Test empty string
//  --------------------------------------------------
    testString = "\0";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

    TEST( returnValue == EXIT_SUCCESS && testInt == 0);


//  Test normal case.
//  --------------------------------------------------

    testString = "123";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

    TEST( returnValue == EXIT_SUCCESS && testInt == 123 );


//  Test normal case.
//  --------------------------------------------------
    testString = "0";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

    TEST( returnValue == EXIT_SUCCESS && testInt == 0 );


//  Test normal case.
//  --------------------------------------------------
    testString = "25";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

    TEST( returnValue == EXIT_SUCCESS && testInt == 25 );

//  Test hex case.
//  --------------------------------------------------
    testString = "0x25";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

//    printf("the hex value of ox25 is 0x%.8x, the decimal value of it is %d\n",testInt, testInt );

    TEST( returnValue == EXIT_SUCCESS && testInt == 37 );

//  Test oct case.
//  --------------------------------------------------
    testString = "015";
    testInt = 0; 
    returnValue = parseKey(testString, &testInt );

//    printf("the oct value of 015 is %o, the decimal value of it is %d\n",testInt, testInt );

    TEST( returnValue == EXIT_SUCCESS && testInt == 13 );

//  Finish test
//  --------------------------------------------------
    printf( "Finished running tests on parseKey()\n" );

}

int
main()
{

    testparseKey();

    return 0;
}

