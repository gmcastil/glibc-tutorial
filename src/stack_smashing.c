#include <stdint.h>
#include <stdio.h>
#include <errno.h>

#ifndef STACK_COMPLAINT_SIZE
	#define STACK_COMPLAINT_SIZE 100
#endif

int main()
{
	uint32_t complaining_array[STACK_COMPLAINT_SIZE];
	uint32_t i;

	/*
	 * When compiled with the normal optimization settings and such, the
	 * array populated by the for loop doesn't actually appear in the
	 * ELF
	 */
	for (i=0; i<sizeof(complaining_array) >> 2; i++) {
		errno = 0;
		complaining_array[i] = i;
		if (errno != 0) {
			fprintf(stderr, "Assignment to array index %d failed with errno %d.\n", i, errno);
		};
	};

#ifdef _USE_COMPLAINING_ARRAY
	/*
	 * So to try to coax the compiler into sticking it into the object file
	 * and it making its way into the ELF, we'll just iterate over it and
	 * modify each element in the array
	 */
	for (i=0; i<sizeof(complaining_array) >> 2; i++) {
		/*
		 * Why not something simpler like squaring or multiplication by 2?
		 * Because a) a multiplication by two is just a shift operation and I
		 * don't want that to be in the machine instructions after it's been
		 * ELF-ed and b) squaring is the kind of thing that I'm assuming compiler
		 * folks have made easier
		 */
		errno = 0;
		complaining_array[i] = i * (i + 3);
		if (errno != 0) {
			fprintf(stderr, "Assignment to array index %d failed with errno %d.\n", i, errno);
		} else {
			printf("complaining_array [%d] = %d\n", i, complaining_array[i]);
		};
	};
#endif

	return 0;
}
