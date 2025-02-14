#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    pid_t pid = fork();
    
    if (pid == 0) {
        char buf[50];
        snprintf(buf, sizeof(buf), "Child PID: %d\n", getpid());
        write(fd, buf, strlen(buf));
        close(fd);
        _exit(0);
    } else {
        char buf[50];
        snprintf(buf, sizeof(buf), "Parent PID: %d\n", getpid());
        write(fd, buf, strlen(buf));
        close(fd);
        wait(NULL);
    }
    return 0;
}