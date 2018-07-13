#include "header.h"

void search_list_system (struct master *mhead, int value)
{
	int pos = 0;
	int count = count_masters (mhead);
	int total = 0;

	for (pos = 1; pos <= count; pos++) {
		total += search_list_value (mhead, pos, value);
	}
	
	if (total > 0) {
		printf ("Total occurrences: %d\n", total);
	} else {
		printf ("No occurrences of given value\n");
	}
}
