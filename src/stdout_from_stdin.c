#include "apue.h"
#include "stdout_from_stdin.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 8192*16

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

//测试结果
//BUFFERSIZE 	real	user	sys
//1          	37.82	1.58	35.31
//4             10.33	0.43	9.61
//8             5.05	0.20	4.59
//32            1.25	0.04	1.19
//128           0.35	0.02	0.31
//512           0.13	0.00	0.12
//1024          0.10	0.00	0.09
//2048          0.07	0.00	0.07
//4096          0.06	0.00	0.05
//8192          0.05	0.00	0.04
//8192*2        0.05	0.00	0.04
//8192*4        0.05	0.00	0.05
//8192*8        0.05	0.00	0.04
//8192*16       0.05	0.00	0.04
