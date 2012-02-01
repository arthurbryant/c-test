#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libmy.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
	printf("Usage: %s fds\n", argv[0]);
	exit(-1);
    }
    print_file_flag(atoi(argv[1]));

    return 0;
}
