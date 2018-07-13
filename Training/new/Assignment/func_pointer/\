#include <stdio.h>
#include <stdlib.h>

int *fun1( void );
int *fun2( void );

int a[3][3];

int main(void)
{
	int (*(*fp)())[3][3];

	fp = fun1;
	printf("%d \n", (*fp())[1][2]);
	fp = fun2;
	printf("%d \n", fp()[0][1][2]);

	return 0;
}


int *fun1( void )
{
	int i,j;
	int k = 1;
//	int a[3][3];

	for(i=0;i<3;i++)
	{
		for(j = 0; j < 3 ;j++)
		{
			a[i][j] = k;
			k += 1;
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	return a;
}


int *fun2( void )
{
	int i,j;
	int k = 10;
//	int a[3][3];

	for(i=0;i<3;i++)
	{
		for(j = 0; j < 3 ;j++)
		{
			a[i][j] = k;
			k += 1;
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return a;
}
