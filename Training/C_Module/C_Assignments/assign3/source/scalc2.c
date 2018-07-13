#include"header.h"
int (*fun_ptr)(int,int);

int callback(int a,int b,int (*fun_ptr)(int,int))
{
	return (fun_ptr(a,b));
}
int main(int argc,char *argv[])
{
    int num1 ;
	num1 = my_atoi(argv[2]);
    int num2;
	num2 = my_atoi(argv[3]);
    switch(*argv[1])
    {
        case '+' :	fun_ptr =sum;
                    printf("sum=%d\n",callback(num1,num2,fun_ptr));
                    break;
   		case '-':	fun_ptr =diff;
                    printf("difference = %d\n",callback(num1,num2,fun_ptr));
                    break;
        case '*':	fun_ptr= mul;
                    printf("product = %d\n",callback(num1,num2,fun_ptr));
                    break;
        case '/' :	fun_ptr = div;
                    printf("division = %d\n",callback(num1,num2,fun_ptr));
                    break;
        default : printf("invalid command\n");
    }
    return 0;
}
                  
