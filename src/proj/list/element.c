#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Define an element struct, which contains a method for creating arbitrary
 * elements, printing a representation of them, and the means to destroy them
 * when requested
*/

void free_element(void *ele_ptr);
struct element *create_element(void *ele_ptr);

struct element {
	void *ele_ptr;
	void (*free_element)(void *ele_ptr);
	void (*repr_element)(void *ele_ptr);
};

struct element *create_element(void *ele_ptr)
{
	struct element *created;
	created = malloc(sizeof(struct element));
	if (created) {
		created->ele_ptr = ele_ptr;
	}
	return created;
}

void free_element(void *ele_ptr)
{
	if (ele_ptr) {
		free(ele_ptr);
	} else {
		fprintf(stderr, "will not attempt to free NULL pointer\n");
	}
}

void repr_element(void *ele_ptr)
{
	fprintf(stdout, "this would be a representation of the element\n");
}

int main(int argc, char *argv[])
{

	void *block = NULL;
	struct element* ptr;

	block = malloc(1024);

	ptr = create_element(block);
	repr_element(ptr);
	free_element(ptr);

	return 0;
}

