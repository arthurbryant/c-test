#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>

int main(int argc, char * argv[])
{
    struct spwd * sp;
    
    if(argc < 2)
    {
        printf("Usage: %s username\n", argv[0]);
        exit(-1);
    }
    setspent();
    if((sp = getspnam(argv[1])) != NULL)
    {
        printf("%s, %s\n", sp->sp_namp, sp->sp_pwdp);
    }
    setspent();
    while((sp = getspent()) != NULL)
    {
        printf("%s, %s\n", sp->sp_namp, sp->sp_pwdp);
    }
    endspent();

    return 0;
}
