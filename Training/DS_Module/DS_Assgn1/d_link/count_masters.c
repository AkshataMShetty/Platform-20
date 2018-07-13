#include "header.h"

int count_masters (struct master *mhead)
{
	int count = 1;
	struct master * temp = mhead;
	if (NULL == mhead) {
		return 0;
	}

	while (temp -> mnext != mhead) {
		count++;
		temp = temp -> mnext;
	}

	return count;
}
