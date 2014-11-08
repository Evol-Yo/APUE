#include "apue.h"
#include "stdout_from_stdin.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 1024

int main()
{
	int n;
	char buf[BUFSIZE];
	struct tms tmsstart, tmsend;
	clock_t start, end;
	int fd;

	if((start = times(&tmsstart)) < 0)
	{
		err_sys("times error\n");
	}

	/*
	 * 打开一个临时文件，进程终止删除该文件
	 */
	if((fd = open("tmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
	{
		err_sys("open file error\n");
	}
	if(unlink("tmp") == -1)
	{
		err_sys("unlink error\n");
	}

	while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
	{
		if(write(fd, buf, n) != n)
			err_sys("write error\n");
	}

	if(n < 0)
		err_sys("read error\n");

	if((end = times(&tmsend)) < 0)
	{
		err_sys("times error\n");
	}

	pr_times(end-start, &tmsstart, &tmsend);

	return 0;
}


