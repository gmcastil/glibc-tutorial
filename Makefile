CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0

top_dir = ./
build_dir = ./build
gnu_build_dir = ./build/gnu
posix_build_dir = ./build/posix
src_dir = ./src

clean:
	@if [ -d $(build_dir) ]; then\
		rm -vrf $(build_dir);\
	fi

errors:
	@if [ ! -d $(build_dir) ]; then\
		mkdir -pv $(build_dir);\
		mkdir -pv $(gnu_build_dir);\
		mkdir -pv $(posix_build_dir);\
	fi

	$(CC) -o $(gnu_build_dir)/errors $(CFLAGS)\
		-D_GNU_SOURCE\
		$(src_dir)/errors.c

	$(CC) -o $(posix_build_dir)/errors $(CFLAGS)\
		-D_XOPEN_SOURCE=700\
		$(src_dir)/errors.c

	$(CC) -o $(gnu_build_dir)/perror $(CFLAGS)\
		-D_GNU_SOURCE\
		$(src_dir)/perror.c
