Summary
-------
This directory contains example code developed based on reading Chapter 3 in the
GNU C library reference.

Notes
-----
After reading through this chapter and working through some basic problems
involving this portion of the C library, I have a few thoughts and advice for
anyone else trying to understand how virtual memory works:
- First off, use this chapter as an opportunity to start learning to use higher
  level development tools like GNU Make and the GDB debugger.  Coming from a
language like Python, where inserting print statements all over the place is
relatively easy, it became readily apparent that a similar use doesn't scale as
easily in C.  Start learning to use the debugger sooner rather than later and
don't avoid learning to set, save, and load breakpoints or watchpoints.  The
debuger has a large set of features and should not be considered as an
afterthought.
- C library versions matter and the library is constantly changing.  To find out
  which version is on your system, at least for GNU systems, you can check the
output of the dynamic linker ``ldd --version`` for a clue.  This is not always
going to work and if there is any doubt, you'll want to dig deeper.  Don't think
this is an edge case you don't need to think about - I spent some time reading
and working to understand the `mallinfo2()` function declared in `malloc.h` only
to discover that the platform I was on (GLIBC 2.31-0ubuntu9.7) didn't include
it, but that a VM I was using (GLIBC 2.35-0ubuntu3) did.  One of the things that
is starting to become apparent to me is that being able to read source code is a
really beneficial skill.
- Google is not your friend - prefer to read the man pages, documentation, or
  even the source code rather than just typing your question into the search
bar.

Questions
---------
Some questions to answer or short projects to work which aid in investigating
these topics:

1. What happens if I try to `malloc()` a very large amount of space?

To investigate this, I made sequentially larger calls to `malloc()` using the
program in `heap_ex1.c`.  After becoming more familiar with the dynamic memory
allocator, in particular with `mallinfo()` I explored this further in
`big_heap.c` which allocates and frees memory in larger chunks and then uses the
`mallinfo()` functions to investigate the state of dynamic allocation for that
particular process.

2. In the process of exploring dynamic memory allocation, I discovered that there
are different limits to the `mallinfo()` and `mallinfo2()` functions due to
differences in C library versions. There should be macros of some sort that
determine C library versions which I can use to determine which version of a
function to call. Create a program that stores the initial state of dynamic
memory allocation for the running process and then makes sequential requests for
heap memory of larger and larger sizes.  After each request, if successful,
store the status of heap memory allocation in a way that supports both
functions depending upon the C library version (the older variant does not
support allocation beyond 4GB).

3. As an exercise in creating class-like objects using pointers and structs,
create a list object description that supports the following:
  - Initialization to a particular length (for now, stick to just `uint32_t`
    type elements)
  - Explore how one might change elements in the list (again, stick to just
    `uint32_t` type elements)
  - Define a method that supports appending new elements to the end of the
    list in the usual way
  - Extend this list class to support arbitrary elements
