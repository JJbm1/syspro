#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execute(char *cmd) {
    char *args[4] = {"/bin/sh", "-c", cmd, NULL};
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char cmd[500];

    while(1) {
        printf("[shell] ");
        if(fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break;
        }
        cmd[strlen(cmd) - 1] = '\0';
        execute(cmd);
    }

    return 0;
}

