#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include "apue.h"

int main()
{
    DIR *dir;
    struct dirent *dp;
    pid_t pid;
    int fd;
    if((dir = opendir("/root/backup")) == NULL)
        err_sys("opendir error");
    if((fd = open("/root/backup/test", O_RDWR)) < 0)
        err_sys("open file error");
    int val;
    val = fcntl(fd, F_GETFD, 0);
    printf("val = %d\n", val);
    close(fd);

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        if(execlp("echo", "pth", "arg1", (char *)0) < 0)
            err_sys("execlp error");
    }
    else
    {
    if((fd = open("/root/backup/test", O_RDWR)) < 0)
        err_sys("open file error");
    int val;
    val = fcntl(fd, F_GETFD, 0);
    printf("val = %d\n", val);
    close(fd);

    }

    return 0;
}
