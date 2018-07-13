/*To count the initial set of characters in buf1 which matches any of the characters in buf2. */

#include"header.h"

int strspn(const char *buf1,const char *buf2)
{
	int index1;
	int index2;
	int count = 0;
	int flag = 0;

	for(index1 = 0 ; *(buf1 + index1) != '\0' ; index1++)
	{
		for(index2 = 0 ; *(buf2 + index2) != '\0' ; index2++)
		{
			if(*(buf1 + index1) == *(buf2 + index2)){
				flag = 1;
				count++;
				break;
			}
		}
		if(!flag){
			return (count);
		}
		flag = 0;
	}	
	return count;
}
