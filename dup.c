#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libmy.h"

int main(int argc, char * argv[])
{
    int fd1, fd2, fd3;
    if((fd1 = open("aa", O_WRONLY)) < 0)
    {
	printf("open file error");
	return -1;
    }
    if((fd2 = dup(fd1)) < 0)
    {
	printf("dup error");
	return -1;
    }
    if((fd3 = open("aa", O_RDWR)) < 0)
    {
	printf("open file again error");
	return -1;
    }
    print_file_flag(fd1);
    /*
    if((val2 = fcntl(fd2, F_GETFL, 0)) < 0)
    {
	printf("get fd2 flag error\n");
	return -1;
    }
    */
	print_file_flag(fd2);
	/*
    if((val3 = fcntl(fd3, F_GETFL, 0)) < 0)
    {
	printf("get fd3 flag error\n");
	return -1;
    }
    */
	print_file_flag(fd3);
    int val1, val2, val3;
    if((val1 = fcntl(fd1, F_GETFL, 0)) < 0)
    {
	printf("get fd1 flag error\n");
	return -1;
    }
    val1 |= O_APPEND; 
    if(fcntl(fd1, F_SETFL, val1) < 0)
    {
	printf("set file flag error\n");
	return -1;
    }
    print_file_flag(fd1);
    print_file_flag(fd2);
	print_file_flag(fd3);
    return 0;
}
