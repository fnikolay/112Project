/******************************************
CMPS 112 C Quicksort Implementation
Ryan Fulscher rfulsche@ucsc.edu
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int partition(int *array, int low, int high) {
  int pivI, pivVal, tempI;
  pivI = (high + low)/2; // Median of Three pivot
  pivVal = array[pivI];
  swap(array, pivI, high);
  tempI = low;
  for (int i = low; i < high; ++i) {
    if (array[i] < pivVal) {
      swap(array, i, tempI);
      ++tempI;
    }
  }
  swap(array, tempI, high);
  return tempI;
}

void sort(int *array, int low, int high) {
  if (low < high) {
    int pivI = partition(array, low, high);
    sort(array, low, pivI - 1);
    sort(array, pivI + 1, high);
  }
}

int main(int argc, char *argv[]) {
  FILE *file;
  if (argc != 2)
    return 0;

  if ((file = fopen(argv[1], "r")) == NULL) {
    perror(argv[1]);
    exit(1);
  }

  char *buffer = NULL;
  size_t nbytes;
  size_t arraysize = 0;
  while (getline(&buffer, &nbytes, file) != EOF) // Read sequence length
    ++arraysize;

  rewind(file);
  int *array = malloc(arraysize*sizeof(int));
  for (int i = 0; i < arraysize; ++i) {
    getline(&buffer, &nbytes, file); // Read values from file
    array[i] = atoi(buffer);
  }
  free(buffer);

  sort(array, 0, arraysize - 1); // Quicksort
  for (int i = 0; i < arraysize; ++i)
    printf("%d\n", array[i]);

  free(array);
  return 0;
}
