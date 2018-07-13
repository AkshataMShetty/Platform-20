#include"header.h"
typedef int (*fun_ptr)(int,int);

int main(int argc,char *argv[])
{
	fun_ptr fp[MAX];
	fp[0] = sum;
	fp[1] = diff;
	fp[2] = mul;
	fp[3] = div;
	int num1 = my_atoi(argv[2]);
    int num2 = my_atoi(argv[3]);
    switch(*argv[1])
    {
        case '+' : 
                    printf("sum=%d\n",fp[0](num1,num2));
                    break;
        case '-':  
                    printf("difference = %d\n",fp[1](num1,num2));
                    break;
        case '*':  
                    printf("product = %d\n",fp[2](num1,num2));
                    break;
        case '/' : 
                    printf("division = %d\n",fp[3](num1,num2));
                    break;
        default : printf("invalid command\n");
    }
	return 0;
}
