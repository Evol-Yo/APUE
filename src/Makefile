all : 	my_ls \
		stdout_from_stdin \
		print_file_status_flags \
		print_type_of_file \
		tmpnam

.PHONY : all

Flags = -g

my_ls : my_ls.c my_ls.h libapue.a
	gcc $(Flags) -o my_ls my_ls.c my_ls.h libapue.a

stdout_from_stdin : stdout_from_stdin.c stdout_from_stdin.h libapue.a
	gcc $(Flags) -o stdout_from_stdin stdout_from_stdin.c stdout_from_stdin.h libapue.a

print_file_status_flags : print_file_status_flags.c
	gcc $(Flags) -o print_file_status_flags print_file_status_flags.c libapue.a

print_type_of_file :
	gcc $(Flags) -o print_type_of_file print_type_of_file.c libapue.a
	
tmpnam : tmpnam.c libapue.a
	gcc $(Flags) -o tmpnam tmpnam.c libapue.a

clear :
	rm 	my_ls \
		stdout_from_stdin \
		print_file_status_flags \
		print_type_of_file \
		tmpnam

