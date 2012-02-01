#include <stdio.h>
#include <limits.h>

#ifdef PATH_NAME
static char * path_name = "define";
#else
static char * path_name = "undefined";
#endif
#ifdef PATH_MAX
static int path= PATH_MAX;
#else
static int path= 1024;
#endif

int main()
{
    printf("%s\n", path_name);
    printf("%d\n", path);

    return 0;
}
