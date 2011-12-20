#include <stdio.h>
#include <malloc.h>
#include <sys/utsname.h>

int main(int argc, char * argv[])
{
    struct utsname * uts;
    uts = (struct utsname*)malloc(sizeof(struct utsname));
    uname(uts);   
    printf("%s %s %s %s %s\n", uts->sysname, uts->nodename, uts->release, uts->version, uts->machine); 

    return 0;
}
