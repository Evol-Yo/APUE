/*
 * print_file_status_flags - 打印文件状态标志
 */

#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int val;

	if(argc != 2)
		err_quit("usage : a.out <descriptor#>");

	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_sys("fcntl error for fd %d", atoi(argv[1]));

	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			err_dump("unknown access mode");
			break;
	}

	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", noblocking");
#if defined(O_SYNC)
	if(val & O_SYNC)
		printf(", synchronous writes");
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if(val & O_FSYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');
	exit(0);

	return 0;
}

#if 0

/*
 * fcntl(2) - 定义在<fcntl.h>头文件中，改变已打开文件的性质
 * Dest：
 * 		(1)复制一个现有的描述符（cmd = F_DUPFD）
 * 		(2)获得/设置文件描述符标记（cmd = F_GETFD 或 F_SETFD）
 * 		(3)获得/设置文件状态标志（cmd = F_GETFL 或 F_SETFL）
 * 		(4)获得/设置异步I/O所有权（cmd = F_GETOWN 或 F_SETOWN）
 * 		(5)获得/设置记录锁(cmd = F_GETLK 、 F_SETLK 或 F_SETLKW)
 */
int fcntl(int fd, int cmd, ... /* arg */ );

#endif
