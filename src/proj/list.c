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
	}
	return lptr;
}

void list_append(struct list *lptr, void *element)
{
	struct node *nptr = malloc(sizeof(struct node));
	if (nptr) {
		nptr->element = element;
		nptr->next = NULL;
	} else {
		printf("couldnt create node\n");
	}

	if ((lptr->head == NULL) && (lptr->tail == NULL)) {
		lptr->head = nptr;
		lptr->tail = nptr;
		lptr->length++;
	} else if (lptr->tail == NULL) {
		lptr->tail = nptr;
		lptr->length++;
	} else {
		printf("unable to append, corrupted list\n");
	}	
}

