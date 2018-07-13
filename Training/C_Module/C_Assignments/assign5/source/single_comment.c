
#include "header.h"

void single_comment()
{
	char ch;
	while((ch = fgetc(fp)) != EOF){
		if(ch == '\n')
			return;
	}
}
