/* Program to rotate left */
int left_rotate_bits(unsigned int num)
{
	if((num & 0x80000000) != 0)
		return (num << 1) ^ 1;
	else
		return num << 1;
}

/* Program to rotate right */

int right_rotate_bits(unsigned int num)
{
    if ((num & 1) != 0)
		return (num >> 1) ^ 0x80000000;
	else
		return num >> 1;
}

/*Program to rotate left by n bits */

int left_rotate_n_bits(unsigned int num,int no_of_bits)
{
    while(no_of_bits != 0)
	{
		if ((num & 0x80000000) != 0)
			num =  ((num << 1) ^ 1);
		else
			num =  (num << 1);
		no_of_bits--;
	}

	return num;
}

/* Program to rotate right by n bits */

int right_rotate_n_bits(unsigned int num,int no_of_bits)
{
    while(no_of_bits != 0)
	{
		if((num & 1) != 0)
			num = ((num >> 1) ^ 0x80000000);
		else
			num = (num >> 1);
		no_of_bits--;
	}
	return num;
}


