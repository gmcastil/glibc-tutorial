MKDIR = /usr/bin/mkdir
CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

TOP = ../..
BUILD = $(TOP)/build

virtual:
	$(MKDIR) -pv $(BUILD)
	$(CC) -o $(BUILD)/malloc_ex1 $(CFLAGS) malloc_ex1.c
	$(CC) -o $(BUILD)/null_deref $(CFLAGS) null_deref.c
	$(CC) -o $(BUILD)/mallinfo_ex1 $(CFLAGS) mallinfo_ex1.c

heap:
	$(MKDIR) -pv $(BUILD)
	$(CC) -o $(BUILD)/heap_ex1 $(CFLAGS) \
		-Wno-unused-parameter \
		-Wno-unused-but-set-variable \
		heap_ex1.c

scratch:
	$(MKDIR) -pv $(BUILD)
	$(CC) -o $(BUILD)/scratch $(CFLAGS) scratch.c

