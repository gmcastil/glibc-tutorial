#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#ifdef WITH_GNU_MALLOC

void *gmalloc(size_t);
void free(void *);

#else

#include "galloc.h"

#endif

int main(int argc, char *argv[])
{
	void *bptr = NULL;
	uint32_t bsize = 1024;

	/* simple case using malloc() and free() via wrapper functions */
	bptr = gmalloc(bsize);
	gfree(bptr);

	return 0;
}

