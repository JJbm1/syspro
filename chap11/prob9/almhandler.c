#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int signo);

void(*signal(int signum, void (*handler)(int)))(int){
	struct sigaction new_action, old_action;

	new_action.sa_handler = handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	
	if(sigaction(signum, &new_action, &old_action) < 0){
                return SIG_ERR;
        }
	return old_action.sa_handler;
}

int main(){
	signal(SIGALRM, alarmHandler);
	alarm(5);
	short i = 0;
	while(1){
		sleep(1);
		i++;
		printf("%d second\n", i);
	}
}

void alarmHandler(int signo){
	printf("Wake up\n");
	exit(0);
}
