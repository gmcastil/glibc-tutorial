#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Define an element struct, which contains a method for creating arbitrary
 * elements, printing a representation of them, and the means to destroy them
 * when requested
 *
 * Starting with a simple example - create a class description for an element
 * that contains
 * - 1KB of memory (so, the element proper will be a non-NULL pointer returned
 *   from malloc()
 * - The length in bytes of the block
 * - A function called purge() that takes as arguments the pointer, the number
 *   of bytes associated with it, and an 8-bit value to cover that region with
 *   (specifically avoiding the problem of values not fitting)
 * - A function called dump() that dumps the contents of the 1KB block to stdout
 *   as an ASCII stream
 * - A function that deallocates the memory obtained from the allocator
 *
 * With these in hand, build a list of 10 elements of 1KB blocks, purge each
 * region with a constant value (e.g., 0x00 for block 0, 0x01 for block 1, etc),
 * then access each, dump it to stdout, then free each element.
*/

#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

struct element {
	void *bptr;
	uint32_t bsize;
	void (*purge)(void *bptr, uint32_t bsize, uint8_t val);
	void (*dump)(void *bptr, uint32_t bsize);
	void (*destroy)(void *bptr, uint32_t bsize);
};

struct element *create_element(uint32_t bsize)
{
	struct element *eptr = malloc(bsize);
	if (eptr) {
		eptr->bsize = bsize;
		fprintf(stdout, "allocated %#x bytes\n", bsize);
	} else {
		fprintf(stderr, "could not allocate %#x bytes\n", bsize);
	}
	return eptr;
}

void purge(void *bptr, uint32_t bsize, uint8_t val)
{
	uint32_t i = 0;
	if (bptr) {
		for (i=0; i<bsize; i++) {
			* ((uint8_t *) bptr) = val;
			bptr = &bptr + 1;
		}
		fprintf(stdout, "purged %#x bytes\n", bsize);
	} else {
		fprintf(stderr, "could not purge NULL pointer\n");
	}
}

void dump(void *bptr, uint32_t bsize)
{
	uint32_t i = 0;
	if (bptr) {
		for (i=0; i<bsize; i++) {
			fprintf(stdout, "%"PRIx8, *(uint8_t *)bptr);
		}
		fprintf(stdout, "\n");
	} else {
		fprintf(stderr, "could not dump NULL pointer\n");
	}
}

void destroy(void *bptr, uint32_t bsize)
{
	purge(bptr, bsize, 0x00);
	free(bptr);
}

int main(int argc, char *argv[])
{
	uint32_t bsize = 1024;
	uint8_t val = 0x55;
	struct element *first = create_element(bsize);

	/* These functions all do what I would expect them to do */
	/* purge(first, bsize, val); */
	/* dump(first, bsize); */
	/* destroy(first, bsize); */

	return 0;
}

