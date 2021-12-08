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

	for (i=0; i<sizeof(complaining_array); i++) {
		errno = 0;
		complaining_array[i] = i;
		if (errno != 0) {
			fprintf(stderr, "Assignment to array index %d failed with errno %d.\n", i, errno);
		};
	};

	return 0;
}
