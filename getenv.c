#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    char *path;
    int i;
    for(i = 1; i < argc; ++i)
    {
    	path = getenv(argv[i]);
    	if(path != NULL)
		printf("%s\n", path);
    }

    return 0;
}
