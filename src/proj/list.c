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

struct list *list_init(void)
{
	struct node *nptr = NULL;
	struct list *lptr = malloc(sizeof(struct list));
	if (lptr) {
		lptr->head = nptr;
		lptr->tail = nptr;
		lptr->length = 0;
	} else {
		printf("couldnt initialize list\n");
		return NULL;
	}
	return lptr;
}

void list_append(struct list *lptr, void *element)
{
	// struct node *prev_nptr = lptr->tail;
	struct node *nptr = malloc(sizeof(struct node));
	/* 
	 * new nodes will always be just the pointer to the element, a pointer
	 * to the previous node, and a NULL pointer to the next node
	*/	
	if (nptr) {
		nptr->element = element;
		nptr->prev = lptr->tail;
		nptr->next = NULL;
	} else {
		printf("couldnt create node\n");
	}

	/*
	 * Obtain pointer to previous node
	 * Modify the next member of the previous node to point to the next node
	 * Modify the tail pointer of the list to point to the next node 
	 * Increment the length member of the list
	 */
	if ((lptr->head == NULL) && (lptr->tail == NULL)) {
		lptr->head = nptr;
		lptr->tail = nptr;
		lptr->length++;
	} else 
	} else {
		printf("unable to append, corrupted list\n");
	}	
}

