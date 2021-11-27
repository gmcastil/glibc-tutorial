#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 256

int main()
{
	int i;
	int retval;

	char *str;
	char buf[BUF_SIZE];

	printf("Predefined Macros:\n");
	printf("\t__LINE__ == %d\n", __LINE__);
	printf("\t__DATE__ == %s\n", __DATE__);
	printf("\t__TIME__ == %s\n", __TIME__);
	if ( __STDC__ == 1 ) {
		printf("\tCompiling of %s conforms to C89 or C99\n", __FILE__);
	} else {
		printf("\tCompiling of %s does not conform to C89 or C99\n", __FILE__);
	};

	printf("Some feature test macros of interest:\n");
	printf("_POSIX_C_SOURCE = %l\n", _POSIX_C_SOURCE);
	printf("_XOPEN_SOURCE = %d\n", _XOPEN_SOURCE);

	printf("\nstrerror() maps error codes to error message strings:\n");
	for (i=0; i<256; i++) {
		str = strerror(i);
		printf("\terrnum = %d: %s\n", i, str);
	};

#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
	printf("\nstrerror_r() POSIX specified at compilation:\n");
	for (i=0; i<256; i++) {
		retval = strerror_r(i, buf, sizeof(buf));
		if (retval == 0) {
			printf("\terrnum = %d: %s\n", i, str);
		} else {
			printf("strerror_r() returned a non-zero value.\n");
		};
	};
#elif _GNU_SOURCE
	printf("\nstrerror_r() GNU specified at compilation:\n");
	for (i=0; i<256; i++) {
		str = strerror_r(i, buf, sizeof(buf));
		printf("\terrnum = %d: %s\n", i, str);
	};
#else
	printf("\nstrerror_r() fail\n");
#endif

	return 0;
}

