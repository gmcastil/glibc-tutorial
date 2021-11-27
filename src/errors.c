#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 256
#define _GNU_SOURCE

int main()
{
	int i;
	char *str;
	char buf[BUF_SIZE];

	printf("The value of the system error number is %d\n", errno);
	printf("Predefined Macros:\n");
	printf("\t__LINE__ == %d\n", __LINE__);
	printf("\t__DATE__ == %s\n", __DATE__);
	printf("\t__TIME__ == %s\n", __TIME__);
	if ( __STDC__ == 1 ) {
		printf("\tCompiling of %s conforms to C89 or C99\n", __FILE__);
	} else {
		printf("\tCompiling of %s does not conform to C89 or C99\n", __FILE__);
	};

	printf("On this platform, predefined error messages are:\n");
	for (i=0; i<256; i++) {
		str = strerror_r(i, buf, sizeof(buf));
		printf("\terrnum %d msg %s\n", i, str);
	};

	return 0;
}

