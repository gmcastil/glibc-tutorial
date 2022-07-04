Pointer Syntax
==============
Two relevant operators are the * and & characters, which have the following
meanings.

- Pointer is a variable that stores the address of another variable.  That's it - I'm not sure why it has to be more complicated than that.
- Contents of a pointer will be a whole number address
- Pointer in C is always initialized to null 

Another couple of significant details.  First, pointers are variables, so things
like `*ip` can be used in the same context as `x`.  Also, and this is very
important, concerning pointer arithmetic: by definition, pointer arithmetic
deals with elements and adjacent objects, not bytes.  So, for example

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int i;
        double *dp;

        dp = malloc(1024 * sizeof(double));
        if (dp) {
                for (i=0; i<1024; i++) {
                        *(dp+i) = i / 3.14;
                }
                for (i=0; i<1024; i++) {
			/* alternately, *(dp+i) */
                        printf("%e\n", dp[i]);
                }
                free(dp);
                return 0;
        } else {
                return 1;
        }
}
```

An interesting question came up while I was doing this, namely on whether or not
to perform manipulate pointers directly or to stick with pointer arithmetic.
As an example, consider this
```c
double *dp1;
double *dp2;

dp1 = malloc(NUM * sizeof(double));
dp2 = malloc(NUM * sizeof(double));

for (i=0; i<NUM; i++) {
	printf("%e\n", *(dp1+i));
}

/* or */

for (i=0; i<NUM; i++) {
	printf("%e\n", *dp2++);
}
```
The problem with the latter is that after the loop terminates, `dp2` points at
an area of memory that was not allocated (or at least, was not allocated in the
earlier call to `malloc()`).  So trying to `free()` it will be problematic. The
natural question to ask is "Is incrementing and decrementing pointers in this
way a bad practice?"  Clearly, the language allows it to be done - but that
doesn't mean that it's a good thing.

