/* to set bit */

#include"header.h"

int setbit(unsigned int src, int pos, int no_of_bits,unsigned int dest)
{
	int bit;
	int result;

	bit = left_rotate_n_bits(dest,no_of_bits);
	result = bit_copy(bit,src,no_of_bits,no_of_bits-1,pos);
	return result;
}
