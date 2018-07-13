#include"header.h"

int main(void)
{
	char *ptr = NULL;
	int num;
	int choice;

	struct frame1 f1;
	struct frame2 f2;
	struct frame3 f3;
	union sample s;


	if(NULL == (ptr = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }
	while(1){
		printf("1.To print the size of the structure frame format\n");
		printf("2.a program to initialize the last element in the union and print the value of other fields.\n");
		printf("3.To find endianess of the machine\n");
		printf("Enter the choice\n");
    	if(NULL == (fgets(ptr,MAX,stdin))){
        	perror("fgets failed");
        	exit(EXIT_FAILURE);
    	}
		choice = my_atoi(ptr);

		switch(choice)
		{
			case 1:
    				printf("sizeof(frame1) = %d\n",sizeof(f1));
    				printf("sizeof(frame2) = %d\n",sizeof(f2));
    				printf("sizeof(frame3) = %d\n",sizeof(f3));
					break;
			case 2:
    				printf("enter the value for e\n");
   					if(NULL == (fgets(ptr,MAX,stdin))){
        				perror("fgets failed");
        				exit(EXIT_FAILURE);
   					}
   					num = my_atoi(ptr);
   					s.e = num;
					printf(" value of a = %d\n",s.a);
    				printf("value of b = %d\n",s.b);
    				printf("value of c = %d\n",s.c);
    				printf("value of d = %d\n",s.d);
    				printf("value of e = %d\n",s.e);
					break;
			case 3:
					endian();
					break;
			case 4: exit(EXIT_FAILURE);
			default : printf("invalid input\n");
		}
	}
	return 0;
}

