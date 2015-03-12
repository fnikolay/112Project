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
    clock_t start = clock(), diff;
    heapSort(A, size);
	diff = clock() - start;

  float msec = diff * 1000 / (float) CLOCKS_PER_SEC;
  int j;
  // for (j = 0; j < i; ++j)
  //   printf("%d\n", A[j]);

  printf("%d\n", (int)msec);

  fclose(fp);
}

void heapSort(int arr[], int length) 
{

    if(length==0) // check if heap is empty
      return;
 
    int t; 

    int n = length, parent = length/2, index, child; 
    // loop until array is sorted

    while (1) { 
        if (parent > 0) { 
            t = arr[--parent];  
        } else {
            n--;                
            if (n == 0) {
                return; 
            }
            t = arr[n];         
            arr[n] = arr[0];    
        }
        //insert operation - pushing t down the heap to replace the parent
        index = parent;
        child = index * 2 + 1; 
        while (child < n) {
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++;
            }
            if (arr[child] > t) {
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


