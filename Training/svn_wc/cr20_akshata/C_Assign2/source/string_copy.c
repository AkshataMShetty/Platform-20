/* To copy n character from buffer sbuf to dbuf */
#include"header.h"
void string_copy(char *dbuf,char *sbuf,int n)
{
	int i;

	for(i = 0 ; (*sbuf != '\0') && (i < n) ; i++)
	{
		*(dbuf + i) = *(sbuf+i);
	}
	*(dbuf + i) = '\0';
	printf("sbuf = %s\n",sbuf);
	printf("dbuf = %s\n",dbuf);
} 
