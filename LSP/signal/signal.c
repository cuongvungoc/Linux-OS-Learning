#include <signal.h>
#include <stdio.h>

static void signal_handler(int sig)
{
    printf("Ouch!\n");
}

int main(int argc, char*argv[])
{
    int j;

    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        printf("ERROR\n");
    }

    for (j = 0; ; j++) {
        printf("%d\n", j);
        sleep(3);
    }
}