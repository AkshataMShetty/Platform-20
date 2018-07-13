#include <stdio.h>

#define token34 34
#define str(x) #x   //stringizing

#define tokenpaster(n) printf ("token" #n " = %d\n", token##n) //token pasting

#define MIN(a,b) ((a)<(b)?(a):(b))  //function like macro

#define PI 3.1415  	//object like macro
#undef PI  			//undefining a macro

#define NUMBER 1  //defining a macro

int main()
{
	
	printf(str(stringizing\n));

	tokenpaster(34);
	
	printf("Minimum between 10 and 20 is: %d\n", MIN(10,20)); 	
 	
//	printf("%f",PI); 	
	
	//conditinal compilation
	#if NUMBER==0  
	printf("Value of Number is: %d\n",NUMBER);  
	#else  
	printf("Value of Number is non-zero\n");  
	#endif     


	#ifdef BUF
		printf("defined=%d\n",BUF);
	
	#else 
		printf("not defined\n");
	#endif

	return 0;
}
