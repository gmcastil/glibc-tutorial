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

	char GREP_BEFORE[] = "Before";
	char GREP_AFTER[] = "After";

	printf("%s ...\n", GREP_BEFORE);
	for (i=0; i<sizeof(complaining_array) >> 2; i++) {
		errno = 0;
		complaining_array[i] = i;
		if (errno != 0) {
			fprintf(stderr, "Assignment to array index %d failed with errno %d.\n", i, errno);
		} else {
			fprintf(stdout, "Assigned %d to array index %d\n", i, complaining_array[i]);
		};
	};
	printf("%s ...\n", GREP_AFTER);

	return 0;
}
