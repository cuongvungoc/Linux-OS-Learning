#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    char *argVec[10] = { "welcome", "to", "lsp", NULL};
    char *envVec[] ={"ENV1=10", "ENV2=100","ENV3=1000",NULL};

    execve(argv[1], argVec, envVec);
    printf("\n This line is not executed in program1\n");
    exit(0);
}