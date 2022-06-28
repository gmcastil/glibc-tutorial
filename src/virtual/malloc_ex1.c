#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	uint32_t length;  /* length of block to request */
	uint32_t *bptr;  /* block pointer */

	/* Get the number of elements to malloc() for */
	printf("Enter a valid uint32_t value: ");
	scanf("%" SCNu32, &length);

	/* Get a block of memory and print out the size of it */
	errno = 0;
	bptr = malloc(length);
	if (bptr) {
		printf("got something\n");
	}
 	printf("errno from malloc() call was %d\n", errno);
 
 	/* Print out the location that it begins */
 
 	/* Print out the contents of the memory that was requested */
 
 	/* Use the same pointer to ask for another and print out its contents */
	return 0;
}

