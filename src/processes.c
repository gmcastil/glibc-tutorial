#include <unistd.h> 
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

int main()
{
#ifdef STACK_COMPLAINT
	uint32_t stack_complaint_array[STACK_COMPLAINT];
#else
	uint32_t stack_complaint_array[10];
#endif
	uint32_t i;

#ifdef SLEEP_TIME
	printf("First, just create a process that sleeps a bit and exits normally.\n\n");
	printf("Sleeping for %d seconds...", SLEEP_TIME);
	/* stdout is line buffered by default */
	fflush(stdout);
	sleep(SLEEP_TIME);
	printf("\n");
#endif /* SLEEP_TIME */

	printf("Attempted to populate an array of %ld uint32_t\n", sizeof(stack_complaint_array) >> 2);
	for (i=0; i<sizeof(stack_complaint_array) >> 2; i++) {
		errno = 0;
		stack_complaint_array[i] = i;
		if (errno != 0) {
			fprintf(stderr, "Assignment of array index %d failed with errno %d.\n", i, errno);
		};
	};

	return 0;
}
