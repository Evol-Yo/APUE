all : 	my_ls \
		stdout_from_stdin \
		print_file_status_flags \
		print_type_of_file \
		tmpnam \
		fork

.PHONY : all

Flags = -g -Wall
apue = -lapue

my_ls : my_ls.c my_ls.h
	gcc $(Flags) -o my_ls my_ls.c my_ls.h $(apue)

stdout_from_stdin : stdout_from_stdin.c stdout_from_stdin.h
	gcc $(Flags) -o stdout_from_stdin stdout_from_stdin.c stdout_from_stdin.h $(apue)

print_file_status_flags : print_file_status_flags.c
	gcc $(Flags) -o print_file_status_flags print_file_status_flags.c $(apue)

print_type_of_file : print_type_of_file.c
	gcc $(Flags) -o print_type_of_file print_type_of_file.c $(apue)
	
tmpnam : tmpnam.c
	gcc $(Flags) -o tmpnam tmpnam.c $(apue)

fork : fork.c
	gcc $(Flags) -o fork fork.c $(apue)

clear :
	rm 	my_ls \
		stdout_from_stdin \
		print_file_status_flags \
		print_type_of_file \
		tmpnam \
		fork

