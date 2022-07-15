/*
 * Implement a list-like data structure with the following features:
 * - Dynamically allocated
 * - Initialize to a length
 * - Support insertion, deletion
*/

#include <stdint.h>
#include <stdlib.h>

#include "list.h"

typedef struct Node {
        void *element;
        void *next;
        void *prev;
} node;

list init_list(uint32_t length)
{
	uint32_t i = 0;
	node *pnode = NULL;

	list l;

	if (length == 0) {
		l.head = NULL;
		l.tail = NULL;
		l.length = length;
	} else if (length <= UINT32_MAX) {
		for (i=0; i<length; i++) {
			/* maybe some sort of recursvie thing where I call a
			 * function to create a node with a pointer to the
			 * previous one and return NULL at the end */
		}
	}
	return l;
}
