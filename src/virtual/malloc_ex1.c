#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>

void squares(uint32_t *bptr, uint32_t num)
{
	uint32_t i;
	uint32_t x;

	for (i=0; i<num; i++) {
		x = *bptr;
		*bptr = x * x;
		bptr++;
	};
}

int main(void)
{
	uint32_t i;

	uint32_t num;
	uint32_t *bptr;

	printf("Enter number of uint32_t elements to store: ");
	scanf("%" SCNu32, &num);

	/* Get a block of memory */
	bptr = malloc(sizeof(uint32_t) * num);
	if (bptr == NULL) {
		printf("ERROR: malloc() returned NULL\n");
		return 1;
	}
	/* Initialize block of memory */
	for (i=0; i<num; i++) {
		*(bptr+i) = i;
	}
	/* Square the entire array */
	squares(bptr, num);

	/* Print out the squared values */	
	for (i=0; i<num; i++) {
		printf("Addr: 0x%p, Data: 0x%08"PRIu32"\n", (void *) (bptr+i), bptr[i]);
	}

	free(bptr);
	return 0;
}

