//mergesort implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void mergeSort(int *array, int s, int f){
  int mid = 0;
  int * temp;
  int len = f - s + 1;
  if (s == f){
    return;
  }
  mid = (s + f) / 2;
  mergeSort(array, s, mid);
  mergeSort(array, mid + 1, f);
  temp = malloc (len*sizeof(int));
  
  int i;
  for(i = 0; i < len; ++i){
    temp[i] = array[s + i];
  }
  int tempS = 0;
  int tempF = mid - s + 1;

  //main for loop that goes through the length
  //of the array
  for(i = 0; i < len; i++){
    if (tempF <= f - s){
      if (tempS <= mid - s){
        //perform the comparison if the left
        //int is larger than the right one
        if(temp[tempS] > temp[tempF]){
          array[i + s] = temp[tempF++];
        }else{
          array[i + s] = temp[tempS++];
        }
      }else{
        array[i + s] = temp[tempF++];
      }
    }else{
      array[i + s] = temp[tempS++];
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

  while(fscanf(fp, "%d", &A[i]) == 1){
    i++;
  }

  clock_t start = clock(), diff;
  mergeSort(A ,0, i);
  diff = clock() - start;

  float msec = diff * 1000 / (float) CLOCKS_PER_SEC;
  //int j;
  //for (j = 0; j < i; ++j)
   // printf("%d\n", A[j]);

  printf("Time taken %.9lf\n", msec);

  fclose(fp);

  return 0;
}

