#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sl_daemon.h"

int main(void) 
{
    pid_t pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) 
    {
        printf("Parent process %d\n", getpid());
        exit(EXIT_SUCCESS);
    }

    // Close all file descriptors
    for (int i = sysconf(_SC_OPEN_MAX); i >= 0; i--) 
    {
        close(i);
    }

    sl_daemon();
    return 0;
}
