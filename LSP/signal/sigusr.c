#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void signal_handler (int signo) 
{
    if (signo == SIGUSR2)
    {
        printf("Chile: Caught SIGUSR2 in child!\n");
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    printf("Child: I am new process clalled by execl()\n");
    printf("Child: new program pid = (%d)\n", getpid());

    if (signal(SIGUSR2, signal_handler) == SIG_ERR) 
    {
        fprintf(stderr, "Cannot handle SIGUSR2!\n");
        exit(-1);
    }       

    for (int i =0; i < argc; i++) {
        printf("\nChild: argv[%d] = (%s)\n", i, argv[i]);
    }

    sleep(5);
    printf("\nChild: sending sigusr1 to parent\n");
    kill(getpid(), SIGUSR1);
    sleep(10);
    printf("\nChild: exiting\n");
    return 0;
}