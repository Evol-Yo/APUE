/*
 * my_ls.c - 列出一个目录中的所有文件
 */
#include "my_ls.h"
#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
	/*
	 * DIR类型是一个directory stream
	 * typedef struct __dirstream DIR <<dirent.h>>
	 */
	DIR		*dp;
	struct dirent	*dirp;

	if(argc != 2)
	{
		err_quit("usage: ls directory_name");
	}
	
	if((dp = opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);

	/*
	 * readdir(3) : It returns NULL on reaching the end of the directory stream or if an error occurred.
	 */
	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);
	
	closedir(dp);

    exit(0);
}
