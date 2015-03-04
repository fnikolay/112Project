//mergesort implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main(int argc, char *argv[]) {
  int arr[10] = {3,4,3,7,1,22,0,6,7,2};
  int len = (sizeof(arr) / sizeof(arr[0]));
  mergeSort(arr, 0 , len - 1);
  int i;
  for (i = 0; i < len; i++){
    printf("[%d]: %d\n",i,arr[i]);
  }
  return 0;
}
