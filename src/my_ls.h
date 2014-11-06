//my_ls.h

#ifndef MY_LS_H
#define MY_LS_H


#if 0
/*
 * dirent - 定义在<dirent.h>中
 */
struct dirent 
{
	ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* not an offset;the current position in the directory stream*/
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
     	                              by all file system types */
    char           d_name[256]; /* filename */
};
#endif


#endif //my_ls.h


