/*
 * Create a program that requests several blocks of heap allocation, stores
 * references to them in an orderly fashion, and displays information about the
 * status of dynamic memory allocation of the process
 *   - Create an array of pointers that will be returned from malloc() calls.
 *   - Create an array of mallinfo2 structs that will be returned from
 *     a sequence of mallinfo2() calls
 *   - For each pointer in the first array, request a block of memory increasing
 *     in size (1KB to 512MB).  After each allocation is
 *     performed, call the mallinfo2() function to obtain information on the
 *     state of dynamic memory allocation, store the result in the second array
 *   - Create a function that pretty prints a `struct mallinfo2` in a single
 *     line to the console
 *   - Using that function, create another function that prints a formatted
 *     table to the console of the state of memory allocation before and after
 *     each of the allocations that are performed.  After this, wait for user
 *     input.
 *   - Upon user pressng a key, free all of the memory that was allocated by the
 *     process and print summary statistics at the end.
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>

#define NUM 10

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
		blocks[i] = malloc(mallsize);
		if (blocks[i]) {
			mi = mallinfo();
			meminfo[i] = &mi;
			mallsize = mallsize << 1;
		} else {
			printf("Error: Could not malloc() with size 0x%zx\n", mallsize);
			return 1;
		}
	}
	for (i=0; i<NUM; i++) {
		if (blocks[i]) {
			free(blocks[i]);
		} else {
			printf("Error: Could not free memory\n");
		}
	}
	return 0;
}

