#include <stdlib.h>

#ifdef WITH_GNU_MALLOC

void *gmalloc(size_t size)
{
	return malloc(size);
}

void gfree(void *ptr)
{
	free (ptr);
}

#else

void *gmalloc(size_t size)
{
	return NULL;
}

void gfree(void *ptr)
{
	return;
}

#endif

