#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // child process continues execution from here
        printf("Child process created and continues execution\n");
    }
    else
    {
        // parent process terminates
        printf("Parent process terminates\n");
        exit(0);
    }
}

int main()
{
    signal(SIGINT, signal_handler);
    while (1)
    {
        // Demonstrate "liveliness" of the process by counting and
        // printing the count value to a file periodically
        static int count = 0;
        count++;
        FILE *fp = fopen("count.txt", "w");
        if (fp != NULL)
        {
            fprintf(fp, "%d", count);
            fclose(fp);
        }
        sleep(1);
    }
    return 0;
}