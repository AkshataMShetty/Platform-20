#include<stdio.h>    
  
void func();  
    
//#pragma startup func  
//#pragma exit func  
	  
//void func() ;  
int main(void){  
	printf("\nI am in main\n");  
//	func();	
}  
	    
void func(){  
	printf("\nI am in func\n");  
	
}  
