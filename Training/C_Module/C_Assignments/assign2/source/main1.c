#include<stdio.h>
#include<string.h>
int main()
{
	char a[0] = "hello";
	char b[1];
	strcpy(b,a);
	printf(b);
	printf("\n");
	
	string_copy(b,a);
	
	return 0;

}
