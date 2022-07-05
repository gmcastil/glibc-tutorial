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
	uint64_t *bptr;
	uint64_t num;
	uint64_t bytes;

	uint32_t malloc_err;

	struct mb;

	num = 0;
	malloc_err = 0;
	while (malloc_err == 0) {
		bytes = sizeof(uint64_t) * num;

		errno = 0;
		bptr = malloc(bytes);
		malloc_err = errno;

		if ( (bptr == NULL) || (malloc_err != 0) ) {
			printf("Attempted to malloc() 0x%" PRIx64 "bytes ", bytes);
			printf("with errno = %" PRId32 "\n", malloc_err);
			break;
		} else {
			struct block mb;
			mb.bptr = bptr;
			mb.num = num;
		}

		/* A chance that malloc() never fails on this platform */
		if (bytes != UINT64_MAX) {
			num++;
		} else {
			printf("Reached maximum number of bytes without malloc() error\n");
			return 0;
		}
		malloc_err = 0;
	}
	free(bptr);
	return 0;
}
