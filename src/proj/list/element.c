#include <stdint.h>
#include <stdlib.h>

/*
 * Define an element struct, which contains a method for creating arbitrary
 * elements, printing a representation of them, and the means to destroy them
 * when requested
*/

struct element {
	void *ele_ptr;
	uint32_t ele_size;
};

void *create_element(void:wq

void free_element(void *ele_ptr)
{
	if (ele_ptr) {
		free(ele_ptr);
	}
}

int main(int argc, char *argv[])
{

	uint32_t *ptra = NULL;
	uint64_t *ptrb = NULL;
	char *ptrc = NULL;

	/* Heap alloc for 32-bit */
	ptra = malloc(sizeof(uint32_t));
	free_element(ptra);

	return 0;
}

