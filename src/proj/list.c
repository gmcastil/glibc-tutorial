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
	struct node *next_nptr = NULL;

	struct list *lptr = malloc(sizeof(struct list));
	if (lptr) {
		/* create and populate n = 0 */
		nptr = (struct node *) malloc(sizeof(struct node));
		if (nptr) {
			/* indicate the start of the list */
			lptr->head = nptr;
			lptr->tail = nptr;
			lptr->length = 1;

			(uint32_t *) nptr->element = &i;
			/* create and populate n = 1 */
			next_nptr = (struct node *) malloc(sizeof(struct node));
			if (next_nptr) {
				i++;
				nptr->next = next_nptr;
				(uint32_t *) next_nptr->element = &i;
			} else {
				printf("couldnt dereference NULL pointer at n = 1\n");
			}
			lptr->tail = next_nptr;
			lptr->length = 2;
			
			/* create and populate n = 2 */
			nptr = (struct node *) malloc(sizeof(struct node));
			if (nptr) {
				i++;
				next_nptr->next = nptr;
				(uint32_t *) nptr->element = &i;
			} else {
				printf("couldnt dereference NULL pointer at n = 2\n");
			}
			lptr->tail = nptr;
			lptr->length = 3;
			
		} else {
			printf("couldnt dereference NULL pointer at n = 0 stage of construction\n");
		}
	}

	return lptr;
}
