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
INCLUDE = $(TOP)/include

$(BIN)/main: $(BUILD)/main.o
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(LDFLAGS) -o $(BIN)/main $(BUILD)/main.o

$(BUILD)/main.o: main.c
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(BUILD)/main.o -c main.c

.PHONY: clean
clean:
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(RM) $(BUILD)/main.o $(BIN)/main
