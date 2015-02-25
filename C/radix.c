#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

long *radix(long *A, long len){
  ListRef buckets[10];
  for(long i = 0; i < 10; i++){
    buckets[i] = newList();
  }

  long max = 0;
  long n = 1;
  long base = 10;
  long digit;

  for (long i = 1; i < len; i++) {
      if (A[i] > max)
        max = A[i];
  }

  while((max / n) > 0){
    for(long i = 0; i < len; i++){
      //printf("%ld ", A[i]);
      digit = A[i] % base;
      digit = digit/n;
      insertAfterLast(buckets[digit], A[i]);
    }

    long index = 0;
    for(long i = 0; i < 10; i++){
      if(!isEmpty(buckets[i])){
        while(!isEmpty(buckets[i])){
          A[index] = getFirst(buckets[i]);
          index++;
          deleteFirst(buckets[i]);
        }
      }
    }

    printf("\n");

    for(long i = 0; i < len; i++){
      printf("%ld ", A[i]);
    }
    printf("\n");
    //printf("\nBase: %ld, n: %ld\n", base, n);
    base *= 10;
    n *= 10;
  }
  return 0;
}

int main(void){
  long *A = malloc(10*sizeof(long));
  srand(time(NULL));

  for(long i = 0; i < 10; i++){
    A[i] = rand();
  }

  radix(A ,10);
}
