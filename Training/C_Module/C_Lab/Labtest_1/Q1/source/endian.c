/* convert number represented in little endian to big endian */

#include "header.h"

int little_to_big_endian(unsigned int num)
{
	unsigned int temp;
	unsigned int result = 0;
	unsigned int temp1;
	unsigned int temp2;

	temp = (num >> 24) | (num << 24);
	temp1 = (num & 0x0000ff00) << 8;
	temp2 = (num & 0x00ff0000) >> 8;
	result = temp | temp1 | temp2;
	return result;
}
