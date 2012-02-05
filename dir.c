#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "apue.h"

char *fullpath = "/root/backup";

int main()
{
    DIR * dir;
    struct dirent * dirent;
    char *p;
    char *current = ".";
    char *parent = "..";
    if((dir = opendir(fullpath)) == NULL)
    {
        err_sys("open dir error");
    }
    while((dirent = readdir(dir)) != NULL)
    {
        p = dirent->d_name;
        if(strcmp(p, current) == 0 || strcmp(p, parent) == 0)
            continue;
        printf("%s ", dirent->d_name);
    }
    printf("\n");

    return 0;
}
