#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#ifdef LEAK_CHECK
#include "galloc.h"
#else

void *gmalloc(size_t);
void gfree(void *);

void *gmalloc(size_t size)
{
	return malloc(sizeof(size));
}

void gfree(void *ptr)
{
	free(ptr);
}

#endif

void null_ptr_err(void *);

void null_ptr_err(void *ptr)
{
	if (ptr == NULL) {
		fprintf(stderr, "NULL pointer found\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	void *bptr = NULL;
	uint32_t bsize = 1024;

	/* simple case using malloc() and free() via wrapper functions */
	bptr = gmalloc(bsize);
	if (bptr) {
		gfree(bptr);
	} else {
		null_ptr_err(bptr);
	}

	return 0;
}

