//mergesort implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void mergeSort(int *array, int left, int right){
  int mid = 0;
  int len = right - left + 1;
  int * temp;
  if (left == right){
    return;
  }
  mid = (left + right) / 2;
  mergeSort(array, left, mid);
  mergeSort(array, mid + 1, right);
  temp = malloc (len*sizeof(int));
  
  int i;
  for(i = 0; i < len; ++i){
    temp[i] = array[left + i];
  }
  
  int m1 = 0;
  int m2 = mid - left + 1;
  
  for(i = 0; i < len; i++){
    if (m2 <= right - left){
      if (m1 <= mid - left){
        if(temp[m1] > temp[m2]){
          array[i + left] = temp[m2++];
        }else{
          array[i+left] = temp[m1++];
        }
      }else{
        array[i+left] = temp[m2++];
      }
    }else{
      array[i + left] = temp[m1++];
    }
  }
  free(temp);
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

  int *A = malloc(size*sizeof(long));
  int i = 0;

  while(fscanf(fp, "%ld", &A[i]) == 1){
    i++;
  }

  clock_t start = clock(), diff;
  mergeSort(A ,0, i);
  diff = clock() - start;

  float msec = diff * 1000 / (float) CLOCKS_PER_SEC;
  int j;
  for (j = 0; j < i; ++j)
    printf("%d\n", A[j]);

  printf("Time taken %.9f\n", msec);

  fclose(fp);

  return 0;
}

