#ifndef PA2_H
#define PA2_H
/*
 * Includes
 */
#include <stdio.h> // for type FILE

/*
 * Constants
 */
#define EXPECTED_ARGS 5

// argument ranges/values
#define PASS_PHRASE_SIZE 8
#define MIN_ROTATE -63
#define MAX_ROTATE +63

// argument parsing
#define DEF_BASE 0
#define FILE_OPEN_OPT "rb"

// Argument indices
#define PASS_PHRASE_INDEX 1
#define KEY_ONE_INDEX 2
#define KEY_TWO_INDEX 3 
#define ROTATE_VALUE_INDEX 4
#define FILE_INDEX 5

// return vals
#define ENDPTR_ERR 1
#define ERANGE_ERR 2 
#define BOUND_ERR 3
#define FILE_ERR 4
#define LENGTH_ERR 5

/* Local function prototypes for MYCRYPT (written in Assembly or C) */
void createMask(unsigned long keys[], char passPhrase[], unsigned long mask[]);
void mycrypt(FILE *inFile, unsigned long mask[], int rotateValue);
int parseInput(char *str, FILE **inFile); 
int parseKey(char *str, unsigned long *key);
int parsePassPhrase(char *str, char *passPhrase);
int parseRotateValue(char *str, long *rotateValue);

/*
 * void rotate( unsigned long mask[], int rotateCnt );
 *
 * Used in assembly routine mycrypt().
 * Commented out here to keep lint happy and as documentation.
 */

#endif /* PA2_H */
