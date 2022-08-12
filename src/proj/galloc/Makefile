PRINTF = /usr/bin/printf
RM = /usr/bin/rm
RMDIR = /usr/bin/rmdir
MKDIR = /usr/bin/mkdir

TOP = .
BUILD = $(TOP)/build
BIN = $(TOP)/bin
LIB = $(TOP)/lib
SRC = $(TOP)/src
INCLUDE = $(TOP)/include

CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

LDFLAGS =

GNU_MALLOC =

ifeq "$(WITH_GNU_MALLOC)" "1"
	MALLOC_DEFS += -DWITH_GNU_MALLOC
else
	MALLOC_DEFS += -UWITH_GNU_MALLOC
endif

$(BIN)/main: $(BUILD)/main.o $(LIB)/libgalloc.so
	$(MKDIR) -pv $(BIN)
	$(CC) $(LDFLAGS) -I$(INCLUDE) -L$(LIB) $(BUILD)/main.o -o $(BIN)/main -lgalloc 

$(BUILD)/main.o: $(SRC)/main.c
	$(MKDIR) -pv $(BUILD)
	$(CC) $(CFLAGS) $(MALLOC_DEFS) -I$(INCLUDE) -c $(SRC)/main.c -o $(BUILD)/main.o

$(LIB)/libgalloc.so: $(SRC)/galloc.c
	$(MKDIR) -pv $(BUILD) $(LIB)
	$(CC) $(CFLAGS) -fPIC -c $(SRC)/galloc.c -o $(BUILD)/galloc.o
	$(CC) $(CFLAGS) -shared $(BUILD)/galloc.o -o $(LIB)/libgalloc.so

.PHONY: clean
clean:
	$(RM) -fv $(BUILD)/main.o $(BIN)/main
	$(RM) -fv $(BUILD)/galloc.o $(LIB)/libgalloc.so
