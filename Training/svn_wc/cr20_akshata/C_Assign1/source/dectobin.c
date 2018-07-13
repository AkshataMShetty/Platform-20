/*converts decimal to binary*/
#include"header.h"

int dec_to_bin(int num)
{
	int index;
	
	for(index = 31 ; index >= 0 ; index--){
		printf("%d",((num >> index) & 0x01));
		if(index % 4 == 0){
			printf(" ");
		}
	}
	printf("\n");
	return num;
}
