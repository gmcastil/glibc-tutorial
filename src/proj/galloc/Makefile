PRINTF = /usr/bin/printf
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
MKDIR = /usr/bin/mkdir

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

LDFLAGS =

TOP = .
BUILD = $(TOP)/build
BIN = $(TOP)/bin
LIB = $(TOP)/lib
SRC = $(TOP)/src
INCLUDE = $(TOP)/include

$(BIN)/main: $(BUILD)/main.o $(LIB)/libgalloc.so
	$(MKDIR) -pv $(BIN)
	$(CC) $(LDFLAGS) -I$(INCLUDE) -L$(LIB) -lgalloc $(BUILD)/main.o -o $(BIN)/main

$(BUILD)/main.o: $(SRC)/main.c
	$(MKDIR) -pv $(BUILD)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/main.c -o $(BUILD)/main.o

$(LIB)/libgalloc.so: $(SRC)/galloc.c
	$(MKDIR) -pv $(BUILD) $(LIB)
	$(CC) $(CFLAGS) -fPIC -c $(SRC)/galloc.c -o $(BUILD)/galloc.o
	$(CC) $(CFLAGS) -shared $(BUILD)/galloc.o -o $(LIB)/libgalloc.so

.PHONY: clean
clean:
	$(RM) -fv $(BUILD)/main.o $(BIN)/main
	$(RM) -fv $(BUILD)/galloc.o $(LIB)/libgalloc.so
