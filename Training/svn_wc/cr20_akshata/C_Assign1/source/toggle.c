/* To toggle even bit */
#include"header.h"

int even_bit_toggle(unsigned int num)
{
	int temp;
	
	temp = num ^  0xAAAAAAAA;
	
	return temp;
}

/* To toggle odd bits */

int odd_bit_toggle(unsigned int num)
{
	int temp2;

	temp2 = num ^ 0x55555555;

	return temp2;
}
