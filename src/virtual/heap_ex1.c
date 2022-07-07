#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>

struct block {
	uint64_t *bptr;
	uint64_t num;
};

int main(int args, char *argv[])
{
	uint64_t *bptr = NULL;
	uint64_t num = 0;
	uint64_t bytes = 0;

	uint32_t malloc_err = 0;

	struct block mb;

	num = 1;
	malloc_err = 0;
	while (malloc_err == 0) {
		bytes = sizeof(uint64_t) * num;

		errno = 0;
		bptr = malloc(bytes);
		malloc_err = errno;

		if ( (bptr == NULL) || (malloc_err == ENOMEM) ) {
			printf("Attempted to malloc() 0x%" PRIx64 "bytes ", bytes);
			printf("with errno = %" PRId32 "\n", malloc_err);
			return 0;
		} else {
			mb.num = num;
			mb.bptr = bptr;
			free(bptr);
		}

		/* A chance that malloc() never fails on this platform */
		if (bytes <= UINT64_MAX) {
			num++;
		} else {
			printf("Reached maximum number of bytes without malloc() error\n");
			return 0;
		}
	}
	return 0;
}
