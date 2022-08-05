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

# Wrap GNU allocator
MALLOC_FLAGS =
WITH_GNU_MALLOC ?= 0
ifeq ($(WITH_GNU_MALLOC), 1)
	MALLOC_FLAGS += -ULEAK_CHECK
else
	MALLOC_FLAGS += -DLEAK_CHECK -I$(INCLUDE)
	LDFLAGS += -L$(LIB) -lgalloc
endif

all: $(LIB)/libgalloc.so $(BUILD)/main.o $(BIN)/main

$(BIN)/main:
	@$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(LDFLAGS) -o $(BIN)/main $(BUILD)/main.o

$(BUILD)/main.o:
	@$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(CFLAGS) $(MALLOC_FLAGS) \
		-o $(BUILD)/main.o -c $(SRC)/main.c

$(LIB)/libgalloc.so:
	@$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(CFLAGS) -fPIC -c $(SRC)/galloc.c -o $(BUILD)/galloc.o
	$(CC) $(CFLAGS) -shared $(BUILD)/galloc.o -o $(LIB)/libgalloc.so

.PHONY: clean
clean:
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(RM) -fv $(BUILD)/main.o $(BIN)/main
	$(RM) -fv $(BUILD)/galloc.o $(LIB)/libgalloc.so
