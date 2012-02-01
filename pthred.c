#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread()
{
    static int i = 0;
    printf("This is %d thread\n", ++i);

    return i;
}

int main(int argc, char * argv[])
{
    pthread_t id;
    pthread_attr_t attr;
    int i, ret, val;

    pthread_attr_init(&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    ret = pthread_create(&id, &attr, (void *)thread, NULL);
    if(ret != 0)
    {
        printf("create thread error\n");
        exit(-1);
    }
    pthread_join(id, (void *)&val);
    printf("val = %d\n", val);
    printf("This is main process\n");
    

    return 0;
}
