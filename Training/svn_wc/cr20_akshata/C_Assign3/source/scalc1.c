#include"header.h"

int (*sum_ptr)(int,int);
int (*diff_ptr)(int,int);
int (*mul_ptr)(int,int);
int (*div_ptr)(int,int);

int main(int argc, char *argv[])
{
	int	num1 =0;
	num1 = my_atoi(argv[2]);
	int num2 = 0;
	num2 = my_atoi(argv[3]);
	switch(*argv[1])
	{
		case '+' :  sum_ptr = sum;
					printf("sum=%d\n",(*sum_ptr)(num1,num2));
					break;
		case '-': 	diff_ptr = diff;
					printf("difference = %d\n",(*diff_ptr)(num1,num2));
					break;
		case '*':   mul_ptr = mul;
					printf("product = %d\n",(*mul_ptr)(num1,num2));
					break;
		case '/' : 	div_ptr = div;
					printf("division = %d\n",(*div_ptr)(num1,num2));
					break;
		default : printf("invalid command\n");
	}
	return 0;
}


