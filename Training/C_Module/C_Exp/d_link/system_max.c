#include "header.h"

int system_max (struct master *mhead)
{
	int count = count_masters (mhead);
	int pos;
	int max = INT_MIN;
	int value;

	for (pos = 1; pos <= count; pos++) {
		value = list_max (mhead, pos);
		if (value > max) {
			max = value;
		}
	}

	return max;
}
