#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>

struct passwd* getpwnam1(const char * name)
{
    struct passwd* ptr;

    setpwent();
    while((ptr = getpwent()) != NULL) 
    {
        if(strcmp(name, ptr->pw_name) == 0)
            break;
    }
    endpwent();

    return ptr;
}
int main(int argc, char * argv[])
{
    /*
    struct passwd* ptr;
    if(argc < 2)
    {
        perror("Usage: program name");
        exit(-1);
    }
    ptr = getpwnam1(argv[1]);
    printf("%s\n", ptr->pw_dir);
    */
    setpwent();
    struct passwd* ptr;
    while((ptr = getpwent()) != NULL)
    {
        printf("%s,\n", ptr->pw_dir);
    }
    endpwent();
    return 0;
}
