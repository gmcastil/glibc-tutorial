# Goal

# Usage

# Design

Two functions `galloc()` and `gfree()` which serve as pass throughs for the GNU
`malloc()` and `free()` functions.

## Considerations
In addition to calling the underlying GNU allocator, the following need to be
kept in mind.
- For successful calls to `malloc()` the value of `errno` is unchanged.
  However, for failed calls, the value is set and should be preserved by the
  wrapper functions (see the GNU C library reference, section 3.2.2, particularly
  the section on portability)
- The `free()` function preserves `errno` so the wrapper should preserve this as
  well
- Several data structures should be maintained during calls to the allocator
  - Number of `malloc()` calls and `free()` calls (successful and failed)
  - Allocation history - during the life of a program, we wish to examine the
    number of successful and failed calls to the allocator, the number of
    attempts to free the memory space, and in some fashion, the amount of
    outstanding memory the allocator believes it has and how much is available
    to be given out to requestors (for the initial design, we will assume
    single-threaded behavior and that `malloc()` statistics are available
    immediately after heap allocation)
  - May use `struct mallinfo` to obtain information from the allocator, but will
    want to maintain my own count as well
- Keep a list of all allocated pointers and all pointers requested to be freed
- Eventually support reallocation - probably by looking at the returned pointer,
  determining if it was changed than what was supplied, and if so, swapping that
  entry in the list of allocated pointers

Since we are assuming a single threaded operation, we can imagine constructing a
sequence of events that occur each time memory is dynamically allocated or
freed.  This motivates creation of a data structure with the following
characteristics

- Singly linked list, with each entry in the list consisting of a struct which
  describes an allocation event
- Each allocation event should contain the following
  - A sequence number, defining the order of calls to the allocator.  Each call
    to `malloc()` and `free()` should each increment the sequence number.
  - An indicator of whether the event is a `malloc()`, `free()`, `realloc()` or
    `calloc()` operation.  This can be a simple 8-bit char of some sort (e.g.,
    `m` for `malloc()`, `f` for `free()`, `r` for `realloc()`, `c` for
    `calloc()`.)
  - A pair of `malloc()` and `free`()` counters, which increment each time a
    call to those functions is made (successful or otherwise).  A third counter
    (and potentially a fourth) should be maintained that counts failed calls to
    `malloc()`.
  - A running tally of outstanding memory (as counted by myself, watching the
    requests go out), the amount of outstanding memory (per the allocator via
    something like `mallinfo`), the amount of requested free memory (manually
    maintained) and the amount of free memory that is reported by the allocator
  - Two lists of successfully `malloc()` and `free()` pointers
  - A single list of all allocated, but unfreed memory, which can be used later
    to indicate which memory has been allocated but unfreed.  Intent here is
    as part of the termination of a program, this list could be iterated over
    and all non-NULL pointers be valid candidates for `free()`.  Reallocation
    may complicate this a bit, so hold off on that for a while

