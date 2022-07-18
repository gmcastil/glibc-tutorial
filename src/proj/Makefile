PRINTF = /usr/bin/printf
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
MKDIR = /usr/bin/mkdir

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g
# Some additional compiler options to use for development - still want to
# ultimately compile without warnings using CFLAGS defined previously
TMPCFLAGS = -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-parameter

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
		$(TMPCFLAGS) \
		-c list.c
	$(CC) -o $(BUILD)/main.o \
		$(CFLAGS) \
		$(TMPCFLAGS) \
		-c main.c
	$(CC) -o $(BIN)/list_ex $(LDFLAGS) $(BUILD)/list.o $(BUILD)/main.o

.PHONY: clean
clean:
	$(RM) -fv $(BUILD)/list.o $(BUILD)/main.o $(BIN)/list_ex

