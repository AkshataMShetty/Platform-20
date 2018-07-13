
#include "header.h"

void check_comment(char ch)
{
	char c;
	if(ch == '/')
	{
		if((c = fgetc(fp)) == '*')
			block_comment();
		else if(c == '/')
			single_comment();
		else{
			fputc(ch, fp2);
			fputc(c, fp2);
		}
	}
	
	else
		fputc(ch, fp2);
}
