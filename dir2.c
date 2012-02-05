#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include "apue.h"

typedef int Myfunc(const char*, const struct stat *, int);

static Myfunc myfunc;
int ftw(char *, Myfunc *);
int do_path(Myfunc *);
static long nreg, nblk, nchr, nfifo, nlnk, nsock, ndir, ntot;

#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4
int main(int argc, char *argv[])
{
    int ret;
    if(argc != 2)
        err_sys("Usage: ftw <staring-path-name>");
    ret = ftw(argv[1], myfunc);
    printf("regual files = %7ld\n", nreg);
    printf("dir files = %7ld\n", ndir);
    printf("block = %7ld\n", nblk);
    printf("char = %7ld\n", nchr);
    printf("fifos = %7ld\n", nfifo);
    printf("symbolic links = %7ld\n", nlnk);
    printf("socks = %7ld\n", nsock);

    return 0;
}
char fullpath[PATH_MAX];
int ftw(char *path, Myfunc *func)
{
    int len = sizeof(path);
    //strncpy(fullpath, path, len);
    strcpy(fullpath, path);
    printf("fullpath = %s\n", fullpath);
    return do_path(func); 
}
int do_path(Myfunc *func)
{
    DIR * dp;
    struct dirent *dirp;
    struct stat statbuf;
    int ret;
    char *ptr;
    if(lstat(fullpath, &statbuf) < 0)
        return func(fullpath, &statbuf, FTW_NS);
    if(S_ISDIR(statbuf.st_mode) == 0)
        return func(fullpath, &statbuf, FTW_F);
    if((ret = func(fullpath, &statbuf, FTW_D)) != 0)
        return ret;
    if((dp = opendir(fullpath)) == NULL)
        return func(fullpath, &statbuf, FTW_DNR);
    ptr = fullpath + strlen(fullpath);
    *ptr++ = '/';
    *ptr = 0;
    while((dirp = readdir(dp)) != NULL)
    {
        if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(ptr, dirp->d_name);
        if((ret = do_path(func)) != 0)
            break;
    }
    ptr[-1] = 0;
    if(closedir(dp) < 0)
        err_sys("close dir error");
    return ret;
}
int myfunc(const char *path, const struct stat *statptr, int type)
{
    switch(type) 
    {
        case FTW_F:
            switch(statptr->st_mode & S_IFMT)
            {
                case S_IFREG: ++nreg; break;
                case S_IFBLK: ++nblk; break;
                case S_IFCHR: ++nchr; break;
                case S_IFIFO: ++nfifo; break;
                case S_IFLNK: ++nlnk; break;
                case S_IFSOCK: ++nsock; break;
                case S_IFDIR: printf("%s should have type FTW_D\n", path);
                              break;
            }
            break;
        case FTW_D:
            ++ndir; break;
        case FTW_DNR:
            printf("can't read dir %s\n", path);
            break;
        case FTW_NS:
            printf("can't stat %s\n", path);
            break;
        default:
            printf("%s unknown type\n", path);
    }
    return 0;
}
