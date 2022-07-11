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

void mi_print(struct mallinfo mi)
{
	printf("\n");
	printf("Non-MMAP allocated space (bytes):\t%8d\n", mi.arena);
	printf("Ordinary free blocks:\t\t\t%8d\n", mi.ordblks);
	printf("Number of fastbin free blocks:\t\t%8d\n", mi.smblks);
	printf("Number of MMAP allocated blocks:\t%8d\n", mi.hblks);
	printf("Space in MMAP allocated regions:\t%8d\n", mi.hblkhd);
	printf("Max total allocated space (bytes):\t%8d\n", mi.usmblks); /* always 0, preserved for backwards compatibility */
	printf("Space in fastbin freed blocks (bytes):\t%8d\n", mi.fsmblks);
	printf("Total allocated space (bytes):\t\t%8d\n", mi.uordblks);
	printf("Total space in freed blocks (bytes):\t%8d\n", mi.fordblks);
	printf("Releaseable free space (bytes):\t\t%8d\n\n", mi.keepcost);
}

int main(int argc, char *argv[])
{
	uint32_t i = 0;
	size_t mallsize = 1024;

	void *blocks[NUM];
	struct mallinfo *meminfo[NUM];
	struct mallinfo mi;

	/* initializing these pointers to all NULL was key to debugging */
	for (i=0; i<NUM; i++) {
		blocks[i] = NULL;
		meminfo[i] = NULL;
	}
	
	for (i=0; i<NUM; i++) {
		printf("Attempted to malloc() %zu bytes", mallsize);
		errno = 0;
		blocks[i] = malloc(mallsize);
		if (blocks[i]) {
			printf("\t\tSUCCESS\n");
			mi = mallinfo();
			meminfo[i] = &mi;
			mallsize = mallsize << 1;
		} else {
			printf("\t\tFAIL\n");
			perror("malloc() returned NULL");
			mi_print(*meminfo[i-1]);
			return 1;
		}
	}
	for (i=0; i<NUM; i++) {
		free(blocks[i]);
	}
	return 0;
}

