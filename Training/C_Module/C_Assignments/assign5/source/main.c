#include "header.h"

FILE *fp;
FILE *fp2;

int main(int argc, char *argv[])
{
	char ch;
	fp = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "w");

	while((ch = fgetc(fp)) != EOF)
		check_comment(ch);

	fclose(fp);
	fclose(fp2);

	return 0;
}
