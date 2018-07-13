#include<stdio.h>
#include<stdlib.h>
//#pragma pack(1)
struct s{
	int a:3;
	int :0;
	short int b:6;
	 int d:2;
//	int e;
//	int f;
//	int g;
//	int h;
//	int i;
//	int j:0;
};

int main()
{
	struct s s1;
	printf("size of s = %d\n",sizeof(s1));
	return 0;
}
