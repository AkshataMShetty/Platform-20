/* To find length of the string */
int string_length(const char *str)
{
	
	int index;
	int len = 0;

	for(index = 0; *(str+index) != '\0' ; index++)
	{
		len++;
	}

	return (len-1);
}
