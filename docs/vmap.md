Wow, so the second chapter of content in the reference manual is on virtual
memory and how it is allocated dynamically. 

Three methods that processes can allocate memory:
  - Invoking the `exec` family of functions
  - Programmatically
  - Forking

The exec method takes program code (an executable) and allocates space for the
instructions within it, as well as constants, literals, and some variables.  It
then transfers control to it.  So, to some degree, the execution method of
memory allocation is essentially just loading a program and certain components
of it into the virtual address space allocated to that process and then running
it.

Programmatic allocation of memory is the method which executing programs are
able to use to obtain additional memory (within the virtual address space).
Memory mapped I/O is another method for doing this - memory mapped I/O is
basically a decree that a certain range of the virtual address space correspond
exactly to the contents of a file.

* Structure of the Virtual Address Space of a Process

The virtual address space allocated to a process consists of segments, three of
which are

The *text segment* is the segment set aside to store the program statements and
constructs (e.g., constants and literals) that was allocated by exec

The *data segment* is the working space set aside to be dynamically allocated
by the process until it is terminated

The *stack segment* is the process stack - it grows as the stack grows, but
isn't allowed to shrink.  This is significant because one can exhaust the amount
of memory allocated to the process by continually increasing the stack (this
will undoubtedly be an experiment).

Memory Allocation

  - Static allocation occurs when a varaible is declared globally or statically
    and the memory to hold it is declared only once by the `exec` procedure and
    is never freed.
  - Local variables or function arguments are declared automatically (whatever
    that means)
  - Dynamic allocation is performed when memory needs are unknown at compile
    time (the program itself needs to determine how much memory to store).  This
    typically done by declaring a variable of pointer type `struct foobar *` and
    then assigning it the address of the space.  Then the operators `*` and `->`
    on that pointer variable can be used to refer to the contents of the space.

```
{
	struct foobar *ptr = malloc (sizeof *ptr);
	ptr->name = x;
	ptr->next = current_foobar;
	current_foobar = ptr;
}
```
