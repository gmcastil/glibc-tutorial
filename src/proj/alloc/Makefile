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

# Wrap GNU allocator
MALLOC_FLAGS =
WITH_GNU_MALLOC ?= 0
ifeq ($(WITH_GNU_MALLOC), 1)
	MALLOC_FLAGS += -ULEAK_CHECK
else
	MALLOC_FLAGS += -DLEAK_CHECK
endif

$(BIN)/main: $(BUILD)/main.o
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) $(LDFLAGS) -o $(BIN)/main $(BUILD)/main.o

$(BUILD)/main.o: main.c
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(CC) \
		$(CFLAGS) \
		$(MALLOC_FLAGS) \
		-o $(BUILD)/main.o -c main.c

.PHONY: clean
clean:
	$(MKDIR) -pv $(BUILD) $(BIN) $(LIB) $(INCLUDE)
	$(RM) -fv $(BUILD)/main.o $(BIN)/main
