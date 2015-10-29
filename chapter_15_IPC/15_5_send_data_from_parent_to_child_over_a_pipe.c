#include <stdio.h>
#include <unistd.h>

#define MAXLINE 256

int main(void)
{
    int n;
    int fd[2];

    pid_t pid;

    char line[MAXLINE];

    if (0 > pipe(fd))
    {
        printf("pipe error\n");
        return -1;
    }

    if ( 0 > (pid = fork()))
    {
        printf("fork error\n");
        return -1;
    }

    /* parent */
    else if ( 0 < pid)
    {
        printf("This is parent.\n");
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
    }

    /* child */
    else 
    {
        printf("This is child.\n");
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }

    return 0;
}
