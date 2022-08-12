#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

struct memsum {
	uint64_t alloc_cnt;
	uint64_t freed_cnt;
	uint64_t alloc_total;
	uint64_t freed_total;
};

struct gmallsumm {

};

void *gmalloc(size_t size)
{
	static struct memstats ms;
	return malloc(size);
}

void gfree(void *ptr)
{
	/* since free() preserves errno, need to save a restore it later */
	int errno_save = errno;

	free (ptr);

	/* see 3.2.3.3 of GNU C library ref */
	errno = errno_save;
}

struct gmallinfo gmallinfo(void)
{
	return struct gmallinfo

}
