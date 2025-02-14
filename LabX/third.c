#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        signal(SIGUSR1, handler);
        pause();
        _exit(0);
    } else {
        sleep(1);
        kill(pid, SIGUSR1);
        wait(NULL);
    }
    return 0;
}