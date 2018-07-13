#include "header.h"

int system_min (struct master *mhead)
{
	int count = count_masters (mhead);
	int pos;
	int min = INT_MAX;
	int value;

	for (pos = 1; pos <= count; pos++) {
		value = list_min (mhead, pos);
		if (value < min) {
			min = value;
		}
	}

	return min;
}
