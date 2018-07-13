
#include "header.h"

void block_comment()
{
	char ch;
	char c;
	while((ch = fgetc(fp)) != EOF){
		if(ch == '*'){
			c = fgetc(fp);
			if(c == '/')
				return;
		}
	}
}
	
