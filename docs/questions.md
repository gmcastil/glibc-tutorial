Processes
---------
Processes are launched within a stack-oriented context that is determined in part
at compile time.  How large can this be on the host machine before problems are
encountered?  What kinds of problems?

What are process signals?  What are the available process signals on Linux?

What was the heartbleed bug on OpenSSL?  When was it discovered, who discovered
it, and what was the root cause?

If large amounts of heap allocation are permitted, the operating system can find
itself in an over-committed state.  How might one do this?

What does the `niceness` column of the `ps` command indicate?

Virtual Memory
--------------

Why does my code in `malloc_ex1.c` show addresses that are 16 bytes apart?
What happens if I ask to malloc() a giant amount of memory?  Try some various
amounts of allocation requests and see what happens if I try to allocate,
deallocate, clear, etc them.

Debugger Questions
------------------
How to print out the contents of a block of memory to the console? To at file?

