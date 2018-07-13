#include<stdio.h>
#include<stdlib.h>
char *cstr = "UBIQUIOUS";
char *str;
char *dstr;
int main()
{
	str = malloc(10);
	printf("0x%08x \n",str);
	str = "gamut";
	printf("0x%08x \n",str);

	dstr = malloc(10);
	printf("0x%08x \n",dstr);
	strcpy(dstr,"OBLATION");
	printf("0x%08x\n",dstr);

	free(str);
	free(dstr);
}
