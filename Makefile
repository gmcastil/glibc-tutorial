CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0

top_dir = ./
build_dir = ./build
src_dir = ./src

errors:
	@if [ -f $(build_dir)/errors ]; then\
		rm -v $(build_dir)/errors;\
	fi
	$(CC) -o $(build_dir)/errors $(CFLAGS) $(src_dir)/errors.c

