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

TOP = .
BUILD = $(TOP)/build
BIN = $(TOP)/bin
LIB = $(TOP)/lib
INCLUDE = $(TOP)/include

.PHONY: list
list:
	$(MKDIR) -pv $(BUILD)
	$(MKDIR) -pv $(BIN)
	$(CC) -o $(BUILD)/list.o \
		$(CFLAGS) \
		-c list.c
	$(CC) -o $(BUILD)/main.o \
		$(CFLAGS) \
		-c main.c
	$(CC) -o $(BIN)/list_ex $(LDFLAGS) $(BUILD)/list.o $(BUILD)/main.o

.PHONY: element
element:
	$(MKDIR) -pv $(BUILD)
	$(MKDIR) -pv $(BIN)
	$(CC) -o $(BUILD)/element.o \
		$(CFLAGS) \
		-c element.c
	$(CC) -o $(BIN)/element $(LDFLAGS) $(BUILD)/element.o 

.PHONY: clean
clean:
	$(RM) -fv $(BUILD)/list.o $(BUILD)/main.o $(BIN)/list_ex
	$(RM) -fv $(BUILD)/element.o $(BIN)/element

