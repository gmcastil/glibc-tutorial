#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int *bptr = malloc(1024);

	if (bptr) {
		fprintf(stdout, "bptr == %p\n", ((void *) bptr));
	} else {
		fprintf(stderr, "bptr is NULL\n");
	}

	fprintf(stdout, "Attempting to free() bptr\n");
	free(bptr);

	if (bptr) {
		fprintf(stdout, "bptr == %p\n", ((void *) bptr));
	} else {
		fprintf(stderr, "bptr is NULL\n");
	}

	return 0;
}

