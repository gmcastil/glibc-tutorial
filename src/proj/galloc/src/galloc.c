#include <stdlib.h>

void *gmalloc(size_t size)
{
	return malloc(size);
}

void gfree(void *ptr)
{
	free (ptr);
}
