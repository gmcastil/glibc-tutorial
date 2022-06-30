#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>

void squares(uint32_t *bptr, uint32_t length)
{
	uint32_t i;
	uint32_t x;

	for (i=0; i<length; i++) {
		x = *bptr;
		bptr[i] = x * x;
		bptr++;
	};
}

int main(void)
{
	uint32_t length;
	uint32_t *bptr;

	uint32_t i;

	printf("Enter a valid uint32_t value: ");
	scanf("%" SCNu32, &length);

	/* Get a block of memory */
	bptr = malloc(length);
	if (bptr == NULL) {
		printf("ERROR: malloc() returned NULL\n");
		return 1;
	}
	/* Initialize block of memory */
	for (i=0; i<length; i++) {
		bptr[i] = i;
	}
	squares(bptr, length);
	for (i=0; i<length; i++) {
		printf("Address 0x%p = %"PRIu32"\n", (void*) &bptr, *bptr);
		bptr++;
	}

	/* Initialize it to a bunch of integers */

	/* Square the entire array */

	/* Print out the squared values */	

	return 0;
}

