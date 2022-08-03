#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#ifdef LEAK_CHECK_ON
void foo()
{
	printf("leak check yes\n");
	return;
}
#else
void foo()
{
	printf("leak check no\n");
	return;
}
#endif

void null_ptr_err(void *);

void null_ptr_err(void *ptr)
{
	if (ptr == NULL) {
		fprintf(stderr, "NULL pointer found\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	void *bptr = NULL;
	uint32_t bsize = 1024;

	/* simple case using malloc() and free() via wrapper functions */
	bptr = malloc(bsize);
	if (bptr) {
		free(bptr);
	} else {
		null_ptr_err(bptr);
	}

	foo();

	return 0;
}

