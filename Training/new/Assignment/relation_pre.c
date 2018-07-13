#include <stdio.h>

#define BUF_SIZE 20000

int main()
{
	#if 0
	#if defined(BUF_SIZE) && defined(BUF)
		printf("bufsize = %d",BUF_SIZE);
	#else
		printf("NOT defined\n");
	#endif
	#endif

	#if 1
	#if BUF_SIZE <= 1024
		printf("less\n");
	#else
		printf("more\n");
	#endif
	#endif

	return 0 ;
}
