CC = /usr/bin/gcc
CFLAGS = -Wall -pedantic -Wextra -ansi -O0 -g

top_dir = ./
build_dir = ./build
gnu_build_dir = ./build/gnu
posix_build_dir = ./build/posix
src_dir = ./src

none:

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

processes:
	@if [ ! -d $(build_dir) ]; then\
		mkdir -pv $(build_dir);\
		mkdir -pv $(gnu_build_dir);\
		mkdir -pv $(posix_build_dir);\
	fi

	$(CC) -o $(gnu_build_dir)/processes $(CFLAGS)\
		-D_GNU_SOURCE\
		-DSTACK_COMPLAINT=100\
		-fno-stack-protector\
		$(src_dir)/processes.c

stack:
	@if [ ! -d $(build_dir) ]; then\
		mkdir -pv $(build_dir);\
		mkdir -pv $(gnu_build_dir);\
		mkdir -pv $(posix_build_dir);\
	fi

	$(CC) -o $(gnu_build_dir)/stack_smashing_canaries\
		-Wall -pedantic -Wextra -ansi -O0 -g\
		-D_GNU_SOURCE\
		-DSTACK_COMPLAINT=100\
		$(src_dir)/stack_smashing.c

	$(CC) -o $(gnu_build_dir)/stack_smashing_no_canaries\
		-Wall -pedantic -Wextra -ansi -O0 -g\
		-fno-stack-protector\
		-D_GNU_SOURCE\
		-DSTACK_COMPLAINT=100\
		$(src_dir)/stack_smashing.c

clean:
	@if [ -d $(build_dir) ]; then\
		rm -vrf $(build_dir);\
	fi

