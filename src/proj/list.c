/*
 * Implement a list-like data structure with the following features:
 * - Dynamically allocated
 * - Initialize to a length
 * - Support insertion, deletion
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#include "list.h"

struct list *init_list(uint32_t length)
{
	uint32_t i = 0;
	struct node *nptr = NULL;

	struct list *lptr = malloc(sizeof(struct list));;
	if (lptr) {
		while (i < length) {
			nptr = (struct node *) malloc(sizeof(struct node));
			if (nptr) {
				lptr->head = nptr;
				lptr->tail = nptr;
				lptr->length = 1;
			} else {
				printf("couldnt dereference NULL pointer\n");
			}
			i++;
		}
	}

	return lptr;
}
