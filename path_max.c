#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

#ifdef OPEN_MAX
static int max = OPEN_MAX;
#else
static int max = 0;
#endif

#define max_guess 256

int main()
{
    if(max == 0)
    {
	errno = 0;
	if((max = sysconf(_SC_OPEN_MAX)) < 0)
	{
	    if(errno == 0)
	    {
		max = max_guess;
	    }
	    else
	    {
		printf("error\n");
		return -1;
	    }
	}
    }
    printf("PATH_MAX=%d\n", PATH_MAX);
    printf("OPEN_MAX=%d\n", max);

    return 0;
}
