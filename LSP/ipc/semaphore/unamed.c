#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

static int glob = 0; // Global variable/ shared resource
sem_t sem;

static void *threadFunc(void *arg)
{
    int loc, j, ret;
    int loops = 10000;
    printf("\n threadFunc (%s) running\n", (char *)arg);
    ret = sem_wait(&sem);

    printf("\n semaphore availed in (%s)\n", (char *)arg);
    if (ret != 0)
        printf("semaphore wait error");
    
    for (j = 0; j < loops; j++)
    {
        loc = glob;
        loc++;
        glob = loc;
    }
    ret = sem_post(&sem);

    if (ret != 0)
    {
        perror("semaphore post error");
    }

    printf("\n threadFunc End for (%s)\n", (char *)arg);
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;
    int loops, s;

    s = pthread_create(&t1, NULL, threadFunc, "thr1");
    if (s != 0)
    {
        perror("pthread_create");
    }

    s = pthread_create(&t2, NULL, threadFunc, "thr2");
    if (s != 0)
    {
        perror("pthread_create");
    }

    s = pthread_create(&t3, NULL, threadFunc, "thr3");
    if (s != 0)
    {
        perror("pthread_create");
    }

    /* creat a unnamed semaphore with pshared = 0*/
    if (sem_init(&sem, 0, 1) == -1)
    {
        perror("Error during se,_init");
        exit(1);
    }

    s = pthread_join(t1, NULL);
    if (s != 0)
        perror("pthead_join");

    s = pthread_join(t2, NULL);
    if (s != 0)
        perror("pthead_join");

    s = pthread_join(t3, NULL);
    if (s != 0)
        perror("pthead_join");

    sem_destroy(&sem);
    printf("\n value of glob after both thread running is = %d\n", glob);
    exit(0);
}