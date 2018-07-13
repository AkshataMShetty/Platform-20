#include "header.h"

int main(int argc, char*argv[1])
{
	FILE *ip;
	FILE *op;
	char *buf = NULL;
	ssize_t len = BUF_SIZE;
	int value;

	if(argc != 2){
		printf("invalid command\n");
		return 0;
	}

	if(NULL == (buf = malloc(sizeof(char*) * BUF_SIZE))){
		printf("malloc failed\n");
		return 0;
	}
	
	ip = fopen(argv[1],"r");
	if(ip == NULL){
		free(buf);
		return 0;
	}
	while(ip != EOF)
	{
		if( -1 == (getline(buf, &len, fp))){
			printf("get line failed\n");
			free(buf);
			return 0;
		}
		
		value = validate(buf);
		if( value == 1){
			op = fopen("output.txt","+w");
			if( op == NULL){
				free(buf);
				return 0;
			}
			fputs(buf,op);
		}
	}
	free(buf);
	return 0;
}
