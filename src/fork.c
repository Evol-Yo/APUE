/*
 * fork - fork函数实例(存在竞争条件)
 *
 * 注意程序中fork与I/O函数之间的交互关系，write函数是不带缓冲的，因为在fork之前调用write，所以
 * 其数据写到标准输出一次。但是，标准I/O库是缓冲的。如果标准输出连接到终端设备，则它是行缓冲的，
 * 否则它是全缓冲的，当以交互方式运行该程序时，只得该printf输出的行一次，其原因是标准输出缓冲区
 * 由换行符冲洗。但是当将标准输出重定向到一个文件时，却得到printf输出行两次。其原因是在fork之前
 * 调用了一次printf，但当调用fork时，该行数据仍在缓冲区中，随后该缓冲区被复制到子进程中。
 */

#include "apue.h"

int glob = 1;
char buf[] = "a write to stdout\n";

int main()
{
	int var;
	pid_t pid;

	var = 6;

	/*
	 * sizeof在编译时计算字符串长度，而strlen需进行一次函数调用
	 */
	if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != (sizeof(buf)-1))
	{
		err_sys("write error");
	}
	printf("before fork\n");
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)	/* child */
	{
		var++;
		glob++;
	}
	else	/* parent */
	{
		sleep(2);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}

#if 0

/*
 * fork - create a child process
 * Desc:
 * 		1.子进程有它自己独一无二的进程ID
 * 		2.子进程的父进程ID和父进程ID相同
 * 		3.子进程不继承父进程的memory locks
 * 		4.子进程的tms_utime、tms_stime、tms_cutime以及tms_ustime被置为0
 * 		5.子进程的未决信号集被设为空
 * 		6.子进程不继承父进程的信号量值
 * 		7.子进程不继承父进程的记录锁
 * 		8.子进程不继承父进程的闹钟
 * 		9.子进程不继承父进程未处理的异步I/O操作
 * 		10.子进程继承父进程的打开文件描述符（意味着共享文件状态标志、当前偏移量、signal-driven I/O attributes）
 * 		11.子进程继承父进程的打开消息队列描述符
 * 		12.子进程继承父进程的打开目录流
 * Note:
 * 		Since  version  2.3.3, a call to fork() is equivalent to a call to clone(2) specifying 
 * 		flags as just SIGCHLD
 */
pid_t fork(void);

#endif
