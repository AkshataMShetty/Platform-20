#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	int i;
	int j;
	int count=0;
	for(j=1;j<argc;j++)
	{
		for(i=0; *( *(argv + j)+ i) != '\0';i++)
		{

			if(*(*(argv + j) +i) == '.' && *(*(argv +j)+ (i+1)) == 'c')
				count++;
		
		}
	}
	printf("the number of cfiles are %d \n", count);
	return 0;
}
