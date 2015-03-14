#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

void heapSort(int arr[], int length);

int main(int argc, char *argv[]){
  FILE* fp = fopen(argv[1], "r+");

  if( fp == NULL ){
    perror("Error while opening the file.\n");
    return 2;
  }
  long size;
  fscanf(fp, "%ld", &size);

  int *A = malloc(size*sizeof(long));
  int i = 0;

  while(fscanf(fp, "%d", &A[i]) == 1){
        i++;
    }
      int j;

    clock_t start = clock(), diff;
    heapSort(A, size);
    for (j = 0; j < i; ++j)
        printf("%d\n", A[j]);
	diff = clock() - start;

  float msec = diff * 1000 / (float) CLOCKS_PER_SEC;


  printf("Time taken %.9f\n", msec);

  fclose(fp);
}

void heapSort(int arr[], int length) 
{
    int temp; 
    int n = length, parent = length/2, index, child; 
    while (1) { 
        if (parent > 0) { 
            temp  = arr[--parent];  
        } else {
            n--;                
            if (n == 0) {
                return; 
            }
            temp  = arr[n];         
            arr[n] = arr[0];    
        }
        index = parent;
        child = index * 2 + 1; 
        while (child < n) {
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++;
            }
            if (arr[child] > temp ) {
                arr[index] = arr[child]; 
                index = child; 
                child = index * 2 + 1; 
            } else {
                break; 
            }
        }
        arr[index] = t; 
    }
}


