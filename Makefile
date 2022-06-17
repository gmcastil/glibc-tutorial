CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

top_dir = ./
build_dir = ./build
gnu_build_dir = ./build/gnu
posix_build_dir = ./build/posix
misc_build_dir = ./build/misc
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

stack:
	@if [ ! -d $(build_dir) ]; then\
		mkdir -pv $(misc_build_dir);\
	fi

	$(CC) -o $(misc_build_dir)/stack_smashing $(CFLAGS)\
		-D_USE_COMPLAINING_ARRAY\
		$(src_dir)/stack_smashing.c

vmap:
	$(CC) -o $(gnu_build_dir)/vmap1 $(CFLAGS)\
		$(src_dir)/vmap1.c

static:
	$(CC) -o $(gnu_build_dir)/static $(CFLAGS)\
		$(src_dir)/static.c

pointers:
	$(CC) -o $(gnu_build_dir)/ptr1 $(CFLAGS)\
		$(src_dir)/ptr1.c

