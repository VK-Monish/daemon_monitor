#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "sl_daemon.h"

void sl_daemon(void) 
{
    const char *log_file = "/home/moni/love.c";
    int fd;
    int count = 0;

    while (1) 
    {
        if (count < 30) 
	{
            fd = open(log_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd == -1) 
	    {
                perror("open");
            } 
	    else 
	    {
                dprintf(fd, "Hello...I am Monish and my roll number is: %d\n", getpid());
                close(fd);
            }
        } 
	else if (count == 30) 
	{
            fd = open(log_file, O_WRONLY | O_TRUNC);
            if (fd == -1) 
	    {
                perror("truncate");
            } 
	    else 
	    {
                close(fd);
            }
        }

        count = (count + 1) % 31;
        sleep(2);
    }
}

