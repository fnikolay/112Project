#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapSort(int arr[], int length);

int main(){
	int d[6] = {3,4,11,1,22,14};
	heapSort(d, 6);
	for(int i=0; i<6; i++)
    	printf("%d ", d[i]);
    	printf("\n");
	return 0;
}

void heapSort(int arr[], int length) 
{
    time_t start;
    time_t end;
    start = time(NULL);
    printf("start: %ld\n", (start));


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
            	end = time(NULL);
            	printf("end: %ld\n", (end));

    			printf("total: %ld\n", (end)-(start));
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


