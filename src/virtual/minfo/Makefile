PRINTF = /usr/bin/printf
RM = /usr/bin/rm
MKDIR = /usr/bin/mkdir

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

LDFLAGS =

TOP = .
BUILD = $(TOP)/build

.PHONY: help
help:
	@$(PRINTF) "Valid make targets are help, clean, and all\n"

.PHONY: clean
clean:
	${RM} -fv $(BUILD)/minfo.o $(BUILD)/minfo

.PHONY: all
all:
	$(CC) -o minfo.o \
		$(CFLAGS) \
		-std=c99 -Wno-unused-parameter -Wno-unused-but-set-variable \
	       	-c minfo.c
	$(CC) -o $(BUILD)/minfo $(LDFLAGS) minfo.o

