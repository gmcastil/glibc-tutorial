#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	uint32_t *ptr = NULL;
	uint32_t i = 42;

	if (ptr == NULL) {
		printf("NULL pointer at %p\n", (void*) &ptr);
	}
	ptr = &i;
	assert(ptr == &i);
	if (ptr) {
		printf("Dereferencing a non-NULL pointer 0x%"PRIu32"\n", *ptr);
		return 0;
	} else {
		printf("Pointer was NULL\n");
		return 1;
	}
}

