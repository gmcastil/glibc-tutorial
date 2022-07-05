Summary
-------
This directory contains example code developed based on reading Chapter 3 in the
GNU C library reference.

Notes
-----
This chapter is a good opportunity to use the GNU debugger to try to really
understand what is happening when a program is executed and learn some
interesting ways to investigate lower level operations by the kernel.

Questions
---------
Some questions to answer

* What happens if I try to `malloc()` a very large amount of space?

Since malloc() normally allocates heap memory, we'll explore this qustion by
requesting larger and larger amounts of heap memory and seeing what happens in
`heap_ex1.c`.

* Modify this previous program to use realloc() instead of malloc() / free()
combinations and then determine if the memory being relocated or just
extended.  What if I malloc(), then malloc() again (so that the heap has two
blocks allocate on it, and then realloc() the first one?  And the second one?

- Once this works in `heap_ex1.c` try to extend this to using a struct that
  contains the pointer to memory, its size, and then also a `fill()`, `dump()` and
`purge()` method involving function pointers as well (

* Can I view the contents of the process stack in GDB?
* What segment does the process stack live within?
* Can an entire segment be dumped to disk? Can the address space of an entire process be dumped to disk?
* If I request a block of memory using the GNU allocator, then free it, is the
  data still visible within that process?
