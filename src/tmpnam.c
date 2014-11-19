/*
 * tmpnam - 创建临时文件
 */

#include "apue.h"

int main()
{
	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;

	/* 
	 * tmpnam(char *s) - If s is not NULL, the name is copied to the character 
	 * 					array (of length at least L_tmpnam) pointed to by s
	 */
	printf("%s\n", tmpnam(NULL));

	tmpnam(name);
	printf("%s\n", name);

	/*
	 * tmpfile() function returns a stream descriptor or NULL
	 */
	if((fp = tmpfile()) == NULL)
	{
		err_sys("tmpfile error");
	}
	fputs("one line of output\n", fp);
	/* 将流设置到起始位置 */
	rewind(fp);
	if(fgets(line, sizeof(line), fp) == NULL)
	{
		err_sys("fgets error");
	}
	fputs(line, stdout);
	exit(0);
}

//example
#if 0
tmp/file65AS2u
tmp/filenP3Rts
one line of output
#endif
