#include <pthread.h>
#include <stdio.h>

static void *printHello(void* argv)
{
        printf("Hello World! This is entry point of thread!\n");
        pthread_exit(NULL);
}

int main (void)
{
        pthread_t threadID;
        int ret;

        ret = pthread_create(&threadID, NULL, printHello, NULL);
        if(ret)
        {
                printf("pthread_create() error number=%d\n", ret);
                return -1;
        }
        pthread_exit(NULL);
}