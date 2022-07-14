/*
 * Implement a list-like data structure with the following features:
 * - Dynamically allocated
 * - Initialize to a length
 * - Support insertion, deletion
*/

#include <stdint.h>
#include <stdlib.h>

struct list list(uint32_t length)
{
	uint32_t i = 0;
	struct *node = NULL;

	struct list l;

	if (length == 0) {
		l = NULL;
		l.tail = NULL;
		l.length = length;
	} else if (length <= UINT32_MAX) {
		break;
	}
	return l;
};

