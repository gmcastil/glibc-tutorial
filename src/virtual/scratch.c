#include <stdio.h>
#include <stdlib.h>

#define NUMS 1024

int main()
{
	int i;
	double *dp;

	dp = malloc(NUMS * sizeof(double));
	if (dp) {
		for (i=0; i<NUMS; i++) {
			*(dp+i) = i / 3.14;
		}
		free(dp);
		return 0;
	} else {
		return 1;
	}
}

