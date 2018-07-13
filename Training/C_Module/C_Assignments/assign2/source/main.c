#include"header.h"
#include<string.h>
sring_copy(char *dbuf,char *sbuf);
int main(void)
{
	char *ptr = NULL;
	int choice;
	int num;
	int num2;
	char *sbuf = NULL;
	char *dbuf = NULL;
	char result;
	char ch;	
	char a[0] = "hello";
	char b[1];
	char c[1];
	if(NULL == (ptr = ((char *)malloc(sizeof(char) * MAX)))){
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}

	 if(NULL == (sbuf = ((char *)malloc(sizeof(char) * MAX)))){
		perror("malloc failure");
		exit(EXIT_FAILURE);
     }

	if(NULL == (dbuf = ((char *)malloc(sizeof(char) * MAX)))){
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}


	while(1)
	{	
		printf("1.to copy n character from source to destination\n");
		printf("2.To append string1 to string2\n");
		printf("3.To append n character from string1 to string2\n");
		printf("4.To compare string1 and string2\n");
		printf("5.To count the initial set of characters in buf1 which matches any of the characters in buf2.\n");
		printf("6.parses buf until it encounters any of the delimiter in delim\n");
		printf("7.To reverse a string\n");
		printf("8.To squeeze the consecutive similar characters in a given string\n");
		printf("9.To check whether rstr is a rotated string of str.\n"); 
		printf("10.To check for the substring sstr in str and if found removes the substring sstr in string str\n"); 
		printf("11.To insert a character in a given string\n");
		printf("12.To check the consecutive occurrences of 3 ones.\n");
		printf("13.Program to print vertical histograms of the lengths of words in its inputs.\n");
		printf("14.exit\n");
		printf("enter your choice\n");

		choice = my_atoi(readinput(ptr));
	
		switch(choice)
		{
			case 1 :	
			//		printf("enter the string\n");
			//		sbuf = readinput(sbuf);
					
			//printf("enter the number of character\n");
					
			//num = my_atoi(readinput(ptr));
					strcpy(c,a);
					printf(c);
				//	string_copy(a,b);
				//	printf(b);
					break;

			case 2:
					printf("Enter the string1\n");
                    sbuf = readinput(sbuf);

                    printf("Enter the string2\n");
                    dbuf = readinput(dbuf);


					printf("string 1 = %s\n",sbuf);
					printf("string 2 = %s\n",dbuf);

					ptr = sappend(sbuf,dbuf);

					printf("appended buffer = %s\n",ptr);

					break;

			case 3:		
					printf("enter the string1\n");
					sbuf = readinput(sbuf);

					printf("enter the string2\n");
					dbuf = readinput(dbuf);

					printf("enter the number of character\n");
					ptr = readinput(ptr);
					num = my_atoi(ptr);

					printf("string1 = %s\n",sbuf);
					printf("string2 = %s\n",dbuf);

					ptr = snappend(sbuf,dbuf,num);

					printf("appended n character = %s\n",ptr);
					
					break;
			case 4:
					printf("enter the string1\n");
					sbuf = readinput(sbuf);

					printf("enter the string2\n");
					dbuf = readinput(dbuf);

					printf("string1 = %s\n",sbuf);
					printf("string2 = %s\n",dbuf);

					result = str_cmp(sbuf , dbuf);
					
					if(result == 0)
						printf("string1 and string2 are equal\n");
					else if(result == 1)
						printf("string1 is greater than string2\n");
					else
						printf("string1 is less than string2\n");
					break;

			case 5 :
					printf("enter the string1\n");
					sbuf = readinput(sbuf);
					
					printf("enter the string2\n");
					dbuf = readinput(dbuf);

					printf("string1 = %s\n",sbuf);
                    printf("string2 = %s\n",dbuf);

					num = strrspn(sbuf,dbuf);
		
					printf("number of characters mataches = %d\n",num);
					
					break;
			case 6 :
					printf("enter the string\n");
					sbuf = readinput(sbuf);

					printf("enter the delimiter\n");
					dbuf = readinput(dbuf);
			
					printf("before parsing string = %s\n",sbuf);

					ptr = strrtok(sbuf,dbuf);
			
					printf("after parsing string = %s\n",ptr);
 
					break;
			case 7 :	
					printf("enter the string\n");
					sbuf = readinput(sbuf);
		
					printf("before reversing the string = %s\n",sbuf);

					dbuf = reverse(sbuf);

					printf("after reversing the string = %s\n",dbuf);
					break;

			case 8 :
					printf("enter the string\n");
                    sbuf = readinput(sbuf);

                    printf("before squeezing the string = %s\n",sbuf);

                    dbuf = squeeze(sbuf);

                    printf("after squeezing the string = %s\n",dbuf);

					break;
			case 9 :
					printf("enter the string\n");
					sbuf = readinput(sbuf);

					printf("enter the rotated string");
					dbuf = readinput(dbuf);

					num = strrot(sbuf,dbuf);
					if(num == 1)
						printf(" string2 is rotated string of string1\n");
					else
						printf(" string2 is not rotated\n");
					break;

			case 10:
					printf("enter the string\n");
					sbuf = readinput(sbuf);

					printf("enter the substring\n");
					dbuf = readinput(dbuf);

					printf("original string = %s\n",sbuf);

					ptr = remsstr(sbuf,dbuf);

					printf("after removing substring = %s\n",ptr);
					break;
			case 11 :
					printf("enter a string\n");
					sbuf = readinput(sbuf);

					printf("enter the position\n");
					num = my_atoi(readinput(ptr));

					printf("enter a character\n");
					ch = getchar();
					

					printf("before inserting a character=%s\n",sbuf);
					dbuf = insertchar(sbuf,ch,num);
					printf("after inserting a character =%s\n",dbuf);
					
					break;

			case 12 :
					printf("enter a enter the size of array\n");
					num = my_atoi(readinput(ptr));
					printf("enter the elements of array in 0 or 1\n");
					if(NULL == (fgets(sbuf,num - 2,stdin))){
				        perror("fgets failed");
        				exit(EXIT_FAILURE);
    				}
					if(validate(sbuf)){
						 num2 = check_ones(sbuf);
					}
					else{
						printf("invalid input\n");
						break;
					}
					if(num2 == 1)
						printf("array consist of 3 consecutive one's\n");
					else
						printf("array does not consist of 3 consecutive one's\n");
					break;

			case 13:
					printf("enter the string\n");
					sbuf = readinput(sbuf);
					
					shistogram(sbuf);
					
					break;
			case 14 :
					exit(EXIT_FAILURE);
			default :
					printf("invalid input\n");
					break;
		}
	}
	free(ptr);
	free(sbuf);
	free(dbuf);
	return 0;
}
