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

.PHONY: wrapped
wrapped:
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(CFLAGS) -fPIC -o $(BUILD)/galloc.o -c $(SRC)/galloc.c
	$(CC) $(CFLAGS) -fPIC -shared -o $(LIB)/libgalloc.so $(BUILD)/galloc.o
	$(CC) $(CFLAGS) -DLEAK_CHECK -I$(INCLUDE) -L$(LIB) -o $(BIN)/main $(SRC)/main.c -lgalloc

#	$(CC) $(CFLAGS) -DLEAK_CHECK -I$(INCLUDE) -o $(BUILD)/main.o -c $(SRC)/main.c
#	$(CC) $(LDFLAGS) -I$(INCLUDE) -L$(LIB) -lgalloc -o $(BIN)/main $(BUILD)/main.o

.PHONY: gnu-malloc
gnu-malloc:
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(CFLAGS) -ULEAK_CHECK -o $(BUILD)/main.o -c $(SRC)/main.c
	$(CC) $(LDFLAGS) -o $(BIN)/main $(BUILD)/main.o

.PHONY: clean
clean:
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(RM) -fv $(BUILD)/main.o $(BIN)/main
	$(RM) -fv $(BUILD)/galloc.o $(LIB)/libgalloc.so
