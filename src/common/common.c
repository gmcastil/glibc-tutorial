#include <stdio.h>

void error(char *msg)
{
        if (msg) {
                printf("ERROR: %s\n", msg);
        } else {
                printf("ERROR: Unknown\n");
        }   
}

