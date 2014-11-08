all : my_ls stdout_from_stdin
.PHONY : all

my_ls : my_ls.c my_ls.h libapue.a
	gcc -g -o my_ls my_ls.c my_ls.h libapue.a

stdout_from_stdin : stdout_from_stdin.c stdout_from_stdin.h libapue.a
	gcc -g -o stdout_from_stdin stdout_from_stdin.c stdout_from_stdin.h libapue.a
