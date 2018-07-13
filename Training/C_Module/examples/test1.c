#include <stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	int count = 0;
	fp = fopen(argv[1],"r");
	char ch;
	while( (ch = fgetc(fp)) != EOF)
	{
		if(ch == ' ' || ch == '\n')
			count++;
	}
	printf("count = %d",count);
}
