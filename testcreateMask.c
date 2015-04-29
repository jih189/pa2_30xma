
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

void
testcreateMask()
{
    unsigned long keys[2];
    char* passphrase;
    int savedRotateCnt;
    unsigned long mask[2] = {0x1,0x2};


    printf( "Testing createMask()\n" );

    /*
     * Test with rotateCnt of 0 - should be no change.
     */
    keys[0] = 0x01234567;
    keys[1] = 0x89ABCDEF;

    passphrase = "abcdefgk";

//     void createMask( keys, passphrase, mask );
//     TEST( mask[0] == keys[0] ^ (unsigned long*)passphrase && mask[1] == 0x89ABCDEF );
    printf( "0x%x\n", *(passphrase) );

    /*
     * Test masking of lower 6 bits of rotateCnt.
     */

//     /* Test with rotateCnt of 64 - should be no change. */
//     mask[0] = 0x01234567;
//     mask[1] = 0x89ABCDEF;

//     rotate( mask, 64 );
//     TEST( mask[0] == 0x01234567 );
//     TEST( mask[1] == 0x89ABCDEF );

//     /* Test with rotateCnt of -64 - should be no change. */
//     /* This also tests negating rotateCnt before masking lower 6 bits. */
//     mask[0] = 0x01234567;
//     mask[1] = 0x89ABCDEF;

//     rotate( mask, -64 );
//     TEST( mask[0] == 0x01234567 );
//     TEST( mask[1] == 0x89ABCDEF );

//     /*
//      * Test rotating left 1 bit.
//      */

//     /* Test with bits to rotate being 0 */
//     mask[0] = 0x7FFFFFFF;
//     mask[1] = 0x7FFFFFFF;


//     rotate ( mask, 1 );
//     TEST( mask[0] == 0xFFFFFFFE );
//     TEST( mask[1] == 0xFFFFFFFE );


//     /* Test with bits to rotate being 1 */
//     mask[0] = 0x80000000;
//     mask[1] = 0x80000000;

//     rotate ( mask, 1 );
//     TEST( mask[0] == 0x00000001 );
//     TEST( mask[1] == 0x00000001 );

//     /*
//      * Test rotating right 1 bit.
//      */

//     /* Test with bits to rotate being 0 */
//     mask[0] = 0xFFFFFFFE;
//     mask[1] = 0xFFFFFFFE;

//     rotate ( mask, -1 );
//     TEST( mask[0] == 0x7FFFFFFF );
//     TEST( mask[1] == 0x7FFFFFFF );

//     /* Test with bits to rotate being 1 */
//     mask[0] = 0x00000001;
//     mask[1] = 0x00000001;

//     rotate ( mask, -1 );
//     TEST( mask[0] == 0x80000000 );
//     TEST( mask[1] == 0x80000000 );

//     /*
//      * Test with rotateCnt > 64 and < -64
//      */

//     /* Test with rotateCnt of 65 - should rotate left 1 bit. */
//     mask[0] = 0x08080808;
//     mask[1] = 0x11111111;

//     rotate( mask, 65 );
//     TEST( mask[0] == 0x10101010 );
//     TEST( mask[1] == 0x22222222 );

//     /* Test with rotateCnt of -65 - should rotate right 1 bit. */
//     /* This also tests negating rotateCnt before masking lower 6 bits. */
//     mask[0] = 0x08080808;
//     mask[1] = 0x11111111;

//     rotate( mask, -65 );
//     TEST( mask[0] == 0x84040404 );
//     TEST( mask[1] == 0x08888888 );

//     /*
//      * Test various # of bits rotate left then right and vice versa
//      *   - should end up with original
//      */

//     mask[0] = 0x01234567;
//     mask[1] = 0x89ABCDEF;

//     rotate( mask, 2 );
//     rotate( mask, -2 );
//     TEST( mask[0] == 0x01234567 );
//     TEST( mask[1] == 0x89ABCDEF );


//     mask[0] = 0x89ABCDEF;
//     mask[1] = 0x01234567;

//     rotate( mask, -17 );
//     rotate( mask, 17 );
//     TEST( mask[0] == 0x89ABCDEF );
//     TEST( mask[1] == 0x01234567 );

//     /*
//      * Test random values; rotating one way and then the opposite way
//      *   calculated by -(64 - rotateCnt) should give us the same values.
//      * For example, rotating +34 should be the same as rotating -30.
//      */

//     mask[0] = mask1[0] = rand();
//     mask[1] = mask1[1] = rand();

//     savedRotateCnt = rand();

//     rotate( mask, savedRotateCnt );
//     rotate( mask1, -(64 - (savedRotateCnt % 64)) );

//     TEST( mask[0] == mask1[0] );
//     TEST( mask[1] == mask1[1] );

    printf( "Finished running tests on rotate()\n" );

}

int
main()
{
    testcreateMask();

    return 0;
}

