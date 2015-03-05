#include <limits.h>
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
    base *= 10;
    n *= 10;
  }
  return A;
}

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("ERROR: Missing input file\n");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r+");

  if( fp == NULL ){
    perror("Error while opening the file.\n");
    return 2;
  }
  long size;
  fscanf(fp, "%ld", &size);

  long *A = malloc(size*sizeof(long));
  int i = 0;

  while(fscanf(fp, "%ld", &A[i]) == 1){
    i++;
  }

  clock_t start = clock(), diff;
  radix(A ,i);
  diff = clock() - start;

  float msec = diff * 1000 / (float) CLOCKS_PER_SEC;
  printf("Time taken %lf\n", msec);

  fclose(fp);

  return 0;
}
