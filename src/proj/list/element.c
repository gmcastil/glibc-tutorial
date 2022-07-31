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

void purge(void *bptr, uint32_t bsize, uint8_t val);

struct element *create_element(uint32_t bsize);
void destroy(struct element *eptr);
void dump(struct element *eptr);

struct element {
	void *bptr;
	uint32_t bsize;
	/*
	void (*purge)(void *bptr, uint32_t bsize, uint8_t val);
	void (*dump)(*bptr, bsize);
	void (*destroy)(void *bptr, uint32_t bsize); */
};

struct element *create_element(uint32_t bsize)
{
	void *bptr = NULL;
	struct element *eptr = NULL;

	eptr = malloc(sizeof(struct element));
	if (eptr) {
		bptr = malloc(bsize);
		if (bptr) {
			eptr->bptr = bptr;
			eptr->bsize = bsize;
			fprintf(stdout, "allocated %#"PRIx32" bytes\n", bsize);
		} else {
			free(eptr);
			fprintf(stderr, "could not allocate %#"PRIx32" bytes\n", bsize);
			exit(1);
		}
	} else {
		fprintf(stderr, "could not allocate %#"PRIx64" bytes\n", sizeof(struct element));
		exit(1);
	}
	return eptr;
}

void purge(void *bptr, uint32_t bsize, uint8_t val)
{
	uint8_t *bptr_8b = bptr;
	uint32_t i = 0;
	if (bptr_8b) {
		for (i=0; i<bsize; i++) {
			*bptr_8b = val;
			bptr_8b++;
		}
		fprintf(stdout, "purged %#"PRIx32" bytes\n", bsize);
	} else {
		fprintf(stderr, "could not purge NULL pointer\n");
		exit(1);
	}
}

void dump(struct element *eptr)
{
	uint32_t i = 0;
	uint32_t j = 1;
	uint8_t *bptr_8b = NULL;
	if (eptr) {
		bptr_8b = (uint8_t *) (eptr->bptr);
		if (bptr_8b) {
			for (i=0; i<(eptr->bsize); i++) {
				fprintf(stdout, "%02"PRIx8, *bptr_8b);
				bptr_8b++;
				if ((j % 8 == 0) && (j != eptr->bsize)) {
					fprintf(stdout, "\n");
				} else if (j % 2 == 0) {
					fprintf(stdout, " ");
				}
				j++;
			}
			fprintf(stdout, "\n");
		} else {
			fprintf(stderr, "could not dump NULL pointer\n");
			exit(1);
		}
	} else {
		fprintf(stderr, "could not derference NULL pointer\n");
		exit(1);
	}
}

/*
void destroy(struct element *eptr)
{
	purge(bptr, bsize, 0x00);
	free(bptr);
	
	 * Note that GNU free() makes no claims it will NULL the pointer, even
	 * though it points to memory that is no longer allocated
	
	bptr = NULL;
}
*/

int main(int argc, char *argv[])
{
	uint32_t bsize = 256;
	uint8_t purgeval = 0x55;
	struct element *first = create_element(bsize);
	dump(first);
	purge(first->bptr, bsize, purgeval);
	dump(first);

	/* Try to purge a destroyed block or soemthing here...not sure */
	/* This should segfault (or be caught by a NULL pointer check) */
	/*purge(first, bsize, val); */

	return 0;
}

