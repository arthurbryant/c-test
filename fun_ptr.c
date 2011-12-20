#include <stdio.h>
#include <stdlib.h>

void fun()
{
    printf("this is void f()\n");
}
int adder(int a, int b)
{
    return a+b;
}

typedef void (*fun_ptr)() ;
typedef int (*atexit_ptr)(fun_ptr);

void my_exit1();
void my_exit2();

int main(int argc, char * argv[])
{
    //int (*add)(int, int);
    atexit_ptr Exit_fun = atexit;
    if(Exit_fun(my_exit1) != 0)
    {
	printf("add exit function error");
	exit(-1);
    }
    if(Exit_fun(my_exit1) != 0)
    {
	printf("add exit function error");
	exit(-1);
    }
    if(Exit_fun(my_exit2) != 0)
    {
	printf("add exit function error");
	exit(-1);
    }
    printf("main done!\n");

    return 0;
}
void my_exit1()
{
    printf("exit1\n");
}
void my_exit2()
{
    printf("exit2\n");
}
