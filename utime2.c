#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat buf;
    struct utimbuf timebuf;
    int i;
    for(i = 1; i < argc; ++i)
    {
        char cmd[256];
        if(stat(argv[1], &buf) < 0)
        {
            printf("stat error\n");
            continue;
        }
        sprintf(cmd, "ls -l %s", argv[i]);
        system(cmd);
        sprintf(cmd, "ls -ul %s", argv[i]);
        system(cmd);
        sprintf(cmd, "ls -cl %s", argv[i]);
        system(cmd);
        printf("\n");
        // change access time to now
        timebuf.actime = time(NULL);
        // keep modify time unchanged
        timebuf.modtime = buf.st_mtime;
        if(utime(argv[i], &timebuf) < 0)
        {
            printf("utime error\n");
            continue;
        }
        sprintf(cmd, "ls -l %s", argv[i]);
        system(cmd);
        sprintf(cmd, "ls -ul %s", argv[i]);
        system(cmd);
        sprintf(cmd, "ls -cl %s", argv[i]);
        system(cmd);
    }

    return 0;
}
