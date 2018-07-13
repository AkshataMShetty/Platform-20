/* C program for Merge Sort */
#include "header.h"

int main()
{
    char *ptr = NULL;
	int arr_size = 0;
	int i = 0;

	if(NULL == (ptr = (char *) malloc (sizeof(char) * MAX ))) {
        perror("malloc failed\n");
        exit(EXIT_FAILURE);
    }   
	printf("enter the size of the array\n");
	if(NULL == ( fgets(ptr,MAX,stdin) )) {
    	perror("fgets failed\n");
        exit(EXIT_FAILURE);
	}   
 
    arr_size = atoi(ptr);
	int arr[arr_size];  	
	printf("enter the elements to the array\n");
	for(i = 0; i < arr_size; i++){	
		if(NULL == ( fgets(ptr,MAX,stdin) )) {
			perror("fgets failed\n");
			exit(EXIT_FAILURE);
		}
			
		arr[i] = atoi(ptr);
	}
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
