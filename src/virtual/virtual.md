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
* Can I view the contents of the process stack in GDB?
* What segment does the process stack live within?
* Can an entire segment be dumped to disk? Can the address space of an entire process be dumped to disk?
* If I request a block of memory using the GNU allocator, then free it, is the
  data still visible within that process?
