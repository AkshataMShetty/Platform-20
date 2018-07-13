/* To copy n bits from from bit position s in snum to bit position d in dnum */

#include"header.h"

int bit_copy(unsigned int snum,unsigned int dnum,int no_of_bit,int src_pos,int des_pos)
{
	int bit;

	bit = getbits(snum,src_pos,no_of_bit);
	while(no_of_bit != 0){
		if(bit_swap2(bit,dnum,no_of_bit-1,des_pos))
			dnum = (1 << des_pos) ^ dnum;
		des_pos --;
		no_of_bit --;
	}

	return dnum;
}
