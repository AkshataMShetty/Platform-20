#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void find_str(FILE *fp, char *str)
{
	char ch;
	int i;
	int count = 0;
	int flag = 0;
	while((ch = fgetc(fp)) != EOF){
		for(i=0; i< strlen(str);i++){
			flag = 0;
			if(ch == *str++)
				flag = 1;
		}
		count++;
	}
	if(flag == 1)
	{
		printf("string str found at %d line \n",count);
	}
	else
	{
		printf("string not found");
	}
}
			

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	char *str;
	str = argv[2];
	find_str(fp,str);
	fclose(fp);
	return 0;
}



