//#include "main.c"

extern int size;

int linear_search(int arr[],int key)
{
	int i;
	for(i = 0 ; i < size ; i++){
		if(arr[i] == key)
			return 1;
	}
	return 0;
}


