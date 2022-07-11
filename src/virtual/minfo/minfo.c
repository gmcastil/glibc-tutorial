/*
 * Create a program that requests several blocks of heap allocation, stores
 * references to them in an orderly fashion, and displays information about the
 * status of dynamic memory allocation of the process
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>
#include <errno.h>

#define NUM 100

int main(int argc, char *argv[])
{
	uint32_t i = 0;
	size_t mallsize = 1024;

	void *blocks[NUM];
	struct mallinfo *meminfo[NUM];
	struct mallinfo mi;

	for (i=0; i<NUM; i++) {
		blocks[i] = NULL;
	}
	
	for (i=0; i<NUM; i++) {

		errno = 0;
		blocks[i] = malloc(mallsize);
		if (blocks[i]) {
			mi = mallinfo();
			meminfo[i] = &mi;
			printf("Successful malloc() of %zu bytes\n", mallsize);
			mallsize = mallsize << 1;
		} else {
			perror("malloc() returned NULL");
			return 1;
		}
	}
	for (i=0; i<NUM; i++) {
		free(blocks[i]);
	}
	return 0;
}

