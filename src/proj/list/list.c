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
		fprintf(stderr, "couldnt initialize list\n");
	}
	return lptr;
}

/* 
 * TODO: Incorporate `const` here so that its clear that neither parameter gets
 * modified
*/
struct node *create_node(struct list *lptr, void *element)
{
	/* 
	 * New nodes are just the pointer to the element, a pointer
	 * to the previous node, and a NULL pointer for the next node
	*/	
	struct node *nptr = malloc(sizeof(struct node));
	if (nptr) {
		nptr->element = element;
		nptr->prev = lptr->tail;
		nptr->next = NULL;
	} else {
		fprintf(stderr, "could not create node\n");
	}
	return nptr;
}

void list_append(struct list *lptr, void *element)
{
	/*
	 * Create a new node
	 * Stick a pointer to the new node in the 'next' member of the previous node
	 * Reassign the tail pointer of the list to the new node
	 * Update the length
	 */
	struct node *nptr = create_node(lptr, element);
	if (nptr) {
		struct node *prev_nptr = NULL;
		if (lptr->head == NULL && lptr->tail == NULL) {
			lptr->head = nptr;
			lptr->tail = nptr;
			lptr->length++;
		} else if (lptr->head == NULL && lptr->tail != NULL) {
			fprintf(stderr, "corrupted list\n");
		} else {
			prev_nptr = lptr->tail;
			prev_nptr->next = nptr;
			lptr->tail = nptr;
			lptr->length++;
		}
	} else {
		fprintf(stderr, "could not append to list\n");
	}
}

