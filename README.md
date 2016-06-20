APUE
====



APUE source学习

    第二遍看APUE了，把一些代码整理整理放在git上吧！欢迎来“添砖加瓦”，同时也可以从中有新的体会
    编译需要将libapue.a加上，例如：
    
        $gcc my_ls.c libapue.a -o my_ls
        或
        $gcc -o my_ls my_ls.c -lapue
        
    也可以在src目录下make (makefile写的不太好啊)
	命令"make clear"清除所有的可执行文件
