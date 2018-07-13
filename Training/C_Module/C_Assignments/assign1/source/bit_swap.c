/* To swap the bit values between source and destination */

int bit_swap(unsigned int num,int source,int destination)
{
	int temp;
	int temp1;
	

	temp = ((num >> source) & 1) ^ ((num >> destination) & 1);
	temp1 = (temp << source)|(temp << destination);
	return num ^ temp1;

	
}	
		
