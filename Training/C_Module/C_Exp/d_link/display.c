#include "header.h"

void display (struct master *mhead)
{
	int count = count_masters (mhead);
	int i;

	for (i = 1; i <= count; i++) {
		printf ("List %d:\n\t", i);
		fwd_display (mhead, i);
	}
}
