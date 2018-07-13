#include <stdio.h>
#include <stdlib.h>

int filecopy(FILE *fp, FILE *fp2)
{
	char ch;
	while((ch = fgetc(fp)) != EOF)
		fputc(ch,fp2);
	return 0;
}
int main(int argc, char *argv[])
{
	FILE *fp;
	FILE *fp2;

	if(argc == 1){
		filecopy(stdin,stdout);
		return 0;
	}
	else if(argc == 2){
		fp = fopen(argv[1],"r");
		filecopy(fp,stdout);
		return 0;
	}
	else if(argc == 3){
		fp = fopen(argv[1],"r");
		filecopy(fp,stdout);
		fp2 = fopen(argv[2],"r");
		filecopy(fp2,stdout);
	}
	else if((argc-1) == '>'){
		fp = fopen(argv[1],"r");
		fp2 = fopen(argv[3],"w");
		filecopy(fp,fp2);
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
