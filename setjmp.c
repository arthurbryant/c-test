#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf jmpbuffer;

static void f1(int, int, int, int, int);
static void f2();

static int gloival;

int main()
{
    int autoival;
    register int regival;
    volatile int volival;
    static int stcival;
    gloival=1; autoival=2; regival=3; volival=4; stcival=5;
    if(setjmp(jmpbuffer) != 0)
    {
        printf("g=%d, a=%d, r=%d, v=%d, s=%d\n", gloival, autoival, regival, volival, stcival);
        exit(0);
    }
    printf("before jump\n");
    gloival=10; autoival=20; regival=30; volival=40; stcival=50;
    f1(gloival, autoival, regival, volival, stcival);
    f2();

    return 0;
}
static void f1(int i, int j, int k, int l, int n)
{
    printf("g=%d, a=%d, r=%d, v=%d, s=%d\n", i, j, k, l, n);
    f2();
}
static void f2()
{
    longjmp(jmpbuffer, 1);
}
