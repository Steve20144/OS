#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    
    if (pid == 0) {
        close(fd[1]);
        char buf;
        read(fd[0], &buf, 1);
        printf("Child received signal\n");
        close(fd[0]);
        _exit(0);
    } else {
        close(fd[0]);
        write(fd[1], "X", 1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}