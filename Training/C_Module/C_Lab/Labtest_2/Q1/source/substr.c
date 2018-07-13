#include"header.h"


int freq_of_occurance(const char *str ,const char *sub_str)
{
	int index1;
	int index2;
	int count = 0;
	int flag =0;

	for(index1 = 0; *(str + index1) != '\0' ; index1++)
	{

		for(index2 =0; *(sub_str + index2 + 1) != '\0' ; index2++)
		{
			flag = 1;
			if(*(str + index1 + index2) != *(sub_str + index2))
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			count++;
		}
		
	}
	return count;
}
