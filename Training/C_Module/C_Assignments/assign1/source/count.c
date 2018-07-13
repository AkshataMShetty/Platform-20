/* To count clear bit */
int count_bit_clear( int num)
{	
	int bit_set_count=0;
	
	while(num != 0){
		if((num & 1) == 0)
			bit_set_count += 1;
		
		num = num >> 1;
	}
	
	return bit_set_count;
}


/* To count set bit */
int count_bit_set(int num)
{
	int bit_set_clear=0;
	
	while(num != 0){	
		if((num & 1) == 1)
			bit_set_clear += 1;
			
		num = num >> 1;
	}
	return bit_set_clear;	
}
