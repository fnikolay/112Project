#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *radix(int *A, int len){
  int n = 1;
  int base = 10;
  int digit, curr;
  int **buckets = (int **)calloc(len+1,sizeof(int));;
  for(int i = 0; i < len; i++){
    digit = A[i] % base;
    digit = digit/n;
    curr = buckets[digit][0]++;
    buckets[digit][curr] = A[i];
    printf("%d\n", digit);
    base *= 10;
    n *= 10;

  }
  return 0;

}

int main(void){
  int *A = malloc(10*sizeof(int));
  srand(time(NULL));

  for(int i = 0; i < 10; i++){
    A[i] = rand();
    printf("%d ", A[i]);
  }
  printf("\n");
  radix(A ,10);
}
