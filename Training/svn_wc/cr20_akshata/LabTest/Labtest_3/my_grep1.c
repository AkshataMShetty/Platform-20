#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 256

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1],"r");
	char *str;
	str = argv[2];
	char *buf;
	int i;
	int j;
	int flag = -1;
	int count = 0;
	if(NULL == (buf = (char*)malloc(sizeof(char)*MAX))){
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}
	if((argc < 3) || (argc > 3)){
		printf("invalid input\n");
		exit(EXIT_FAILURE);
	}
	while(buf=fgets(buf, 80,fp)){
		
		if((strstr(buf,str))){
			flag = count;
		}
		count++;
	
		if(flag + 1 == count){
			printf("pattern found in line %d in file %s\n",count,argv[1]);
		}
	}

	if(flag == -1)
		printf("pattern not found in file %s\n",argv[1]);
	return 0;

}
