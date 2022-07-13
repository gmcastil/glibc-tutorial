PRINTF = /usr/bin/printf
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
MKDIR = /usr/bin/mkdir

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

LDFLAGS =

TOP = ../..
LIB = $(TOP)/lib

.PHONY: common
common:
	$(MKDIR) -pv $(LIB)
	$(CC) -o $(LIB)/common.o $(CFLAGS) -fPIC -c common.c
	$(CC) -o $(LIB)/libcommon.so $(LDFLAGS) -shared $(LIB)/common.o
	$(RM) -vf $(LIB)/common.o

