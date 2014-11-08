#ifndef STDOUT_FROM_STDIN_H
#define STDOUT_FROM_STDIN_H

#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>

#if 0
/*
 * tms - 定义在<sys/times.h>头文件中
 */
struct tms
{
    clock_t tms_utime;		/* User CPU time.  */
    clock_t tms_stime;		/* System CPU time.  */

    clock_t tms_cutime;		/* User CPU time of dead children.  */
    clock_t tms_cstime;		/* System CPU time of dead children.  */
};
#endif

/*
 * pr_times - 打印进程时钟时间、用户cpu时间、系统cpu时间（以秒为恶单位）
 * @real：时钟时间（clock_t）
 * @tmsstart:初始时间
 * @tmsend:终止时间
 */

void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
	static long clktck = 0;
	if(clktck == 0)
		if((clktck = sysconf(_SC_CLK_TCK)) < 0)
			err_sys("sysconf error");
	printf(" real: %7.2f\n", real / (double) clktck);
	printf(" user: %7.2f\n", (tmsend->tms_utime - tmsstart->tms_utime) / (double) clktck);
	printf(" sys : %7.2f\n", (tmsend->tms_stime - tmsstart->tms_stime) / (double) clktck);
}

#endif //stdout_from_stdin.h
