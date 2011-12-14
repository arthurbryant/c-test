#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread()
{
    static int i = 0;
    printf("this is %d thread\n", ++i);
    return 10;
}

int main(int argc, char * argv[])
{
    pthread_t id;
    int i, ret;
    int thread_ret;
    for(i = 0; i < 3; ++i)
    {
        ret = pthread_create(&id, NULL, (void *)thread, NULL);
        if(ret != 0)
        {
            printf("create thread error!\n");
            exit(-1);
        }
    }
    //printf("%d\n", id);
    printf("this is main process!\n");
    pthread_join(id, (void *)&thread_ret);
    printf("%d\n", thread_ret);
    printf("this is main process end!\n");

    return 0;
}
