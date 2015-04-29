
/*
 * Unit Test for createMask.s
 *
 * void createMask( unsigned long keys[], char passphrase[], unsigned long mask[] );
 *
 * xor keys[0] with passphrase[0-3] 
 * xor keys[1] with passphrase[4-7] 
 *
 * update mask with mask[0] = xor keys[0] with passphrase[0-3] 
 *                  mask[1] = xor keys[1] with passphrase[4-7] 
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For rotate() function prototype */

#define LONG_SIZE 4

void
testcreateMask()
{
    unsigned long keys[2];
    char* passphrase;
    int savedRotateCnt;
    unsigned long mask[2] = {0x1,0x2};

    printf( "Testing createMask()\n" );

    /*
     * Test case 1: normal case
     */

    keys[0] = 0x01234567;
    keys[1] = 0x89ABCDEF;

    passphrase = "abcdefgh";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    /*
     * Test case 2: passphrase contain space charcter
     */

    keys[0] = 0xFE304923;
    keys[1] = 0xE09ABFF0;

    passphrase = "apple si";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    /*
     * Test case 3: passphrase contain random character
     */

    keys[0] = 0xF1F2F3F4;
    keys[1] = 0x98765432;

    passphrase = "!@#$%^&*";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    /*
     * Test case 4: passphrase contain "" and keys value with 0 and -1
     */

    keys[0] = 0x00000000;
    keys[1] = 0xFFFFFFFF;

    passphrase = "\0 acb\0ep";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    /*
     * Test case 5: special 0
     */

    keys[0] = 0x00000000;
    keys[1] = 0x00000000;

    passphrase = "\00000000";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    /*
     * Test case 6: normal case
     */

    keys[0] = 0x8AB72332;
    keys[1] = 0x292283E2;

    passphrase = "00000000";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    /*
     * finish test
     */

    printf( "Finished running tests on createMask()\n" );

}

int
main()
{
    testcreateMask();

    return 0;
}

