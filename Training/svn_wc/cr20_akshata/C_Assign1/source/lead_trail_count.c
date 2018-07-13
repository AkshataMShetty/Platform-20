#include"header.h"

/* To count leading set bit */
int cnt_leading_set_bits(int num)
{
	int count = 0;
	
	while(num & 0x80000000)
	{
		count ++;
		num <<= 1;
	}
	return count;
}

/* To count leading cleared bits */
int cnt_leading_cleared_bits(int num)
{
	int count = 0;

	while(!(num & 0x80000000))
	{
		count++;
		num <<= 1;
	}
	return count;
}

/* To count trailing cleared bits */
int cnt_trailing_cleared_bits(int num)
{
	
	int count = 0;

	while(!(num & 1))
	{
		count ++;
		num >>= 1;
	}

	return count;
}

/* To count trailing set bits */
int cnt_trailing_set_bits(int num)
{
	int count = 0;
	while(num & 1)
	{
		count ++;
		num >>= 1;
	}
	
	return count;
}
