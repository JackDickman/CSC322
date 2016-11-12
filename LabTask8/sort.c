#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef int *pointer;
typedef int intarray[5];
typedef pointer pointerarray[5];

//-----------------------------------------------------------------

void initialize(intarray a, pointerarray b) {
  int i;
  for(i = 0; i < SIZE; i++) {
    a[i] = rand();
  }

  int j;
  for(j = 0; j < SIZE; j++) {
    b[j] = &a[j];
  }
}

//----------------------------------------------------------------- 

void printIntegers(intarray a) {
  int i;
  for(i = 0; i < SIZE; i++) printf(" %2d : %12d\n",i,a[i]);
}

//----------------------------------------------------------------- 

void printPointers(pointerarray a) {
  int i;
  for(i = 0; i < SIZE; i++) printf(" %2d : %12d\n",i,*a[i]);
}

//----------------------------------------------------------------- 

void sortIntegers(intarray a) {
  int i;
  for(i = 0; i < SIZE; i++) {
    int j = 0;
    while(j < SIZE - (i + 1)) {
      if(*(a + j) > *(a + j + 1)) {
        int temp = *(a + j + 1);
        *(a + j + 1) = *(a + j);
        *(a + j) = temp;
      }
      j++;
    }
  }
}

//----------------------------------------------------------------- 

void sortPointers(pointerarray a) {
  int i;
  for(i = 0; i < SIZE; i++) {
    int j = 0;
    while(j < SIZE - (i + 1)) {
      if(*(*(a + j)) > *(*(a + j + 1))) {
        int *temp = *(a + j + 1);
        *(a + j + 1) = *(a + j);
        *(a + j) = temp;
      }
      j++;
    }
  }
}

//----------------------------------------------------------------- 

int main(void) {
  intarray integers;
  pointerarray pointers;

  printf("\n");

  printf("---- Initialized array of integers ----\n");
  initialize(integers, pointers);
  printIntegers(integers);

  int **p;
  p = pointers;

  printf("---- Sorted array of pointers ----\n");
  sortPointers(pointers);
  printPointers(pointers);

  printf("---- Sorted array of integers ----\n");
  sortIntegers(integers);
  printIntegers(integers);

  printf("---- Array of pointers ----\n");
  printPointers(p);

  printf("\n");

  return(EXIT_SUCCESS);
}
