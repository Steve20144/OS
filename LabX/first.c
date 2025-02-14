#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	for(int i=0; i<3;i++){
		pid_t pid = fork();
		if(pid == 0){
			printf("Child PID: %d\n", getpid());
			_exit(0);
		} else if(pid<0){
			perror("fork");
			return 1;
		}

	}

	while(wait(NULL)>0);
	return 0;
}
	
