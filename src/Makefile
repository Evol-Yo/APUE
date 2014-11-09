all : 	my_ls \
		stdout_from_stdin \
		print_file_status_flags
.PHONY : all

my_ls : my_ls.c my_ls.h libapue.a
	gcc -g -o my_ls my_ls.c my_ls.h libapue.a

stdout_from_stdin : stdout_from_stdin.c stdout_from_stdin.h libapue.a
	gcc -g -o stdout_from_stdin stdout_from_stdin.c stdout_from_stdin.h libapue.a

print_file_status_flags : print_file_status_flags.c
	gcc -g -o print_file_status_flags print_file_status_flags.c libapue.a

clear :
	rm 	my_ls \
		stdout_from_stdin \
		print_file_status_flags
