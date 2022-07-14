PRINTF = /usr/bin/printf
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
MKDIR = /usr/bin/mkdir

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

LDFLAGS =

TOP = ../..
BUILD = $(TOP)/build
BIN = $(TOP)/bin
LIB = $(TOP)/lib
INCLUDE = $(TOP)/include

.PHONY: list
list:
	$(MKDIR) -pv $(BUILD)
	$(CC) -o $(BUILD)/list.o \
		$(CFLAGS) \
		-Wno-unused-but-set-variable \
		-Wno-unused-parameter \
		-c list.c
	$(CC) -o $(BIN)/list $(LDFLAGS) $(BUILD)/list.o

.PHONY: clean
clean:
	$(RM) -fv $(BUILD)/list.o $(BIN)/list

