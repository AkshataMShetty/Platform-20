/* swap the bit values between source in snum and destination in dnum */

#include"header.h"

int bit_swap2(unsigned int snum,unsigned int dnum,int source,int destination)
{
	
	if(((snum >> source) & 1) != ((dnum >> destination) & 1))
		return 1;
	else
		return 0;
}
