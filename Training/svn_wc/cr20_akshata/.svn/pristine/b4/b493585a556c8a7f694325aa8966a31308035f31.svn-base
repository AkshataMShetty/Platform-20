#include "header.h"
int main()
{
    char *ptr = NULL;
	int n = 0;
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
 
    n = atoi(ptr);
	int arr[n];  	
	printf("enter the elements to the array\n");
	for(i = 0; i < n; i++){	
		if(NULL == ( fgets(ptr,MAX,stdin) )) {
			perror("fgets failed\n");
			exit(EXIT_FAILURE);
		}
			
		arr[i] = atoi(ptr);
	}
 

    printf("Given array is \n");
    printArr(arr, n);
	
	quickSortIterative( arr, 0, n - 1 );
    
	printArr( arr, n );
    return 0;
}
