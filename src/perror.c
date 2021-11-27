#include <stdio.h>
#include <errno.h>

int main()
{
	char *msg = "This was sent to stderr - the next line will say Success";
	char *empty_msg;

	printf("This was sent to stdout\n");
	perror(msg);

	/* 

	Now for some interesting stuff...

	First, we'll call perror() with a null pointer and watch the output
	that appears on stdout

	*/

	perror(empty_msg);

	/*

	That's odd.  The reason is because when perror() is called with an
	empty string or a null pointer, it just uses whatever message
	corresponds to the current value of errno, which at this point is 0.

	*/

	errno = 119;
	perror(empty_msg);

	/*
	
	'No XENIX semaphores available' is unlikely to be an error message
	returned on a modern platform.

	*/

	return 0;
}
