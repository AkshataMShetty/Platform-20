/* Program to print vertical histograms of the lengths of words in its inputs.*/

#include"header.h"

int shistogram(char *str)
{
	int index = 0;
	int count = 0;
	int j = 0;
	char *word = NULL;
	if(NULL == (word = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }

	for(index = 0;*(str + index) != '\0' ;index++){
		if(*(str + index) == ' ' || *(str + index) == '\n' || *(str + index) == '\t'){
			*(word + j) = count;
			j++;
			count = 0;
		}
		else 
			count++;
	}
	*(word + index) = '\0';
	for(index = 30; index >= 0; index--){
		for(j = 0;*(word + j) != '\0' ;j++){
			if(index >= *(word + j))
				printf(" ");
			else
				printf("*");
			printf(" ");
		}
		printf("\n");
	}
	return 1;
	free(word);
}
