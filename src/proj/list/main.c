#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "list.h"

#define DEFAULT_LENGTH 5

void error(char *msg)
{
	printf("%s\n", msg);
}

int main(int argc, char *argv[])
{
        uint32_t length = 0;
	uint32_t i = 0;

        char *a = NULL;

	struct list *new_list;

        if (argc == 1) {
		new_list = list_init();
        } else if (argc == 2) {
                a = argv[1];
                if (a) {
                        length = (uint32_t) atoi(a);
			new_list = list_init();
			for (i=0; i<length; i++) {
				list_append(new_list, &i);
			}
                } else {
                        error("NULL pointer returned");
                        return 1;
                }
        } else {
                error("Too many command line arguments");
                return 1;
        }
        return 0;
}

