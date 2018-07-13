/* to get n bits */

int getbits(int num,int pos,int no_of_bits)
{
	return  num & (num >> ((pos + 1) - no_of_bits) ^ (~(~(0) << no_of_bits)));
}

