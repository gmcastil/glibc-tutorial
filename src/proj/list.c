/*
 * Implement a list-like data structure with the following features:
 * - Dynamically allocated
 * - Initialize to a length
 * - Support insertion, deletion
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define DEFAULT_LENGTH 5  /* default length if not supplied at runtime */

struct node {
	void *element;
	void *prev;
	void *next;
};

void error(char *msg)
{
	printf("ERROR: %s\n", msg);
}

int main(int argc, char *argv[])
{
	uint32_t length = 0;

	char *a = NULL;

	/* Create a doubly-linked list of length supplied as an argument */
	if (argc == 1) {
		length = DEFAULT_LENGTH;
	} else if (argc == 2) {
		a = argv[1];
		if (a) {
			length = (uint32_t) atoi(a);
		} else {
			error("NULL pointer returned");
			return 1;
		}
	} else {
		error("Too many command line arguments");
		return 1;
	}
	return 0;
}
