#include <stdio.h>
int main(void)
{
	char *src = "hello";
	char *temp;
	char *dst;
	//temp=dst;


	printf("%p\n%d",temp,*temp);
	printf("%p\n,%d",dst,*dst);

	
	*temp  = 'h' ;

	
//	strcpy(dst,src);
//	printf("%s",dst);	
	printf("%d\n",*temp);
	
	

/*	printf("%p\n",src);
	printf("%p\n",dst);
	printf("%s\n",cha);*/
	return 0;
}

