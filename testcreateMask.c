
/*
 * Unit Test for createMask.s
 *
 * void createMask( unsigned long keys[], char passphrase[], unsigned long mask[] );
 *
 * Lower 6 bits of rotateCnt is masked to keep rotate range 0-63.
 *
 * Positive rotateCnt - rotate left
 * Negative rotateCnt - rotate right
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

    keys[0] = 0x01234567;
    keys[1] = 0x89ABCDEF;

    passphrase = "abcdefgh";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );


    keys[0] = 0xFE304923;
    keys[1] = 0xE09ABFF0;

    passphrase = "apple si";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    keys[0] = 0xF1F2F3F4;
    keys[1] = 0x98765432;

    passphrase = "!@#$%^&*";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    keys[0] = 0x00000000;
    keys[1] = 0xFFFFFFFF;

    passphrase = "\0 acb\0ep";

    createMask( keys, passphrase, mask );
    TEST( mask[0] == ( keys[0] ^ *((unsigned long*)passphrase) ) &&
          mask[1] == ( keys[1] ^ *((unsigned long*)(passphrase+LONG_SIZE)) )
        );

    printf( "Finished running tests on createMask()\n" );

}

int
main()
{
    testcreateMask();

    return 0;
}

