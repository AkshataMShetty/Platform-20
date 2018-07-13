#include<stdio.h>
int main()
{
	unsigned int a = -3;


	int b = 3;
	if(a < b)
		printf("a is less than b\n");
	else
		Printf("a is greater then b\n");


	if(1 < -1)
		printf("1 is less than -1\n");
	else
		printf("-1 is less than 1\n");

	return 0;
}
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
#include<stdio.h>
int main()
{
	char x = 'A';
	int *ptr = NULL;
	ptr = &x;
	printf("%c",*ptr);
	printf("%p,%p\n",&x,&ptr);
	return 0;
}
