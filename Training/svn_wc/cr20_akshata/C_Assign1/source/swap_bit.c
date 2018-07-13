#include"header.h"

int swap_bit(unsigned int snum,unsigned int dnum,int source,int destination)
{
	int num1;
//	int temp;
	int xor1;
	int xor2;

	num1 = ((snum >> source) & 1) ^ ((dnum >> destination) & 1);
//   	temp = (num1 << source) | (num1 << destination);
  	xor1 = (num1 << source) ^ snum;
   	xor2 = (num1 << destination) ^ dnum;
   	printf("snum :");
   	dec_to_bin(xor1); 
   	printf("dnum :");
   	dec_to_bin(xor2);
	return 0;
}

