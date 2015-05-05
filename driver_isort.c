/*
 * driver for extra credit program for CSE 30 PA2 - mycrypt.
 *
 * Randomly populates an array of ints and calls isort() to perform
 * an insertion sort.
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 400
#define MAXINT 65536

int isort(int arr[], int len);

int main() {

  srand(17);

  int arr[ARRSIZE];

  int i;
  for (i = 0; i < ARRSIZE; ++i) {
    arr[i] = rand() % MAXINT;
  }

  int res = isort(arr, ARRSIZE);

  for (i = 0; i < ARRSIZE; ++i) {
    printf("%5d ", arr[i]);
    if (i % 8 == 7) {
      printf("\n");
    }
  }

  printf("\nMax - Min = %d\n", res);

  return 0;
}
