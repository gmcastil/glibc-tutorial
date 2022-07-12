PRINTF = /usr/bin/printf
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
MKDIR = /usr/bin/mkdir

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

LDFLAGS =

TOP = .
BUILD = $(TOP)/build

.PHONY: help
help:
	@$(PRINTF) "Valid make targets are help, clean, and all\n"

.PHONY: heap
heap:
	$(MKDIR) -pv $(BUILD)
	$(CC) -o $(BUILD)/heap_ex1 $(CFLAGS) \
		-Wno-unused-parameter \
		-Wno-unused-but-set-variable \
		heap_ex1.c

.PHONY: minfo
minfo:
	$(MKDIR) -pv $(BUILD)
	$(CC) -o $(BUILD)/minfo.o \
		$(CFLAGS) \
		-std=c99 \
		-Wno-deprecated-declarations \
		-Wno-unused-parameter -Wno-unused-but-set-variable \
	       	-c minfo.c
	$(CC) -o $(BUILD)/minfo $(LDFLAGS) $(BUILD)/minfo.o

.PHONY: clean
clean:
	${RM} -fv $(BUILD)/*.o
	${RM} -fv $(BUILD)/minfo $(BUILD)/heap_ex1 $(BUILD)/malloc_ex1
	${RMDIR} -v $(BUILD)

.PHONY: all
all: minfo heap
	$(MKDIR) -pv $(BUILD)

	$(CC) -o $(BUILD)/malloc_ex1 $(CFLAGS) malloc_ex1.c
	$(CC) -o $(BUILD)/null_deref $(CFLAGS) null_deref.c

