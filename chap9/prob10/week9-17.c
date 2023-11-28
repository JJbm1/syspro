#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXARG 10

int main() {
    char *args[MAXARG];
    char input[256];
    char *saveptr;
    int background;

    while (1) {
        printf("Pls input cmd : ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Parent process end\n");
            printf("Exit\n");
            exit(0);
        }

        input[strlen(input) - 1] = '\0';

        int i = 0;
        background = 0;

        args[i] = strtok_r(input, " \n", &saveptr);
        while (args[i] != NULL && i < MAXARG - 1) {
            if (strcmp(args[i], "&") == 0) {
                background = 1;
                args[i] = NULL;
            }
            i++;
            args[i] = strtok_r(NULL, " \n", &saveptr);
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                exit(1);
            }
        } else {
            printf("[%d] Parent process start\n", getpid());
            if (background) {
                printf("[%d] child process start\n", pid);
                sleep(1);
            }
            int status;
            waitpid(pid, &status, 0);
            if(WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                printf("Parent process end\n");
                printf("Exit\n");
                exit(1);
            }
            if (!background) {
                if(WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                    printf("SUCCESS\n\n");
                } else {
                    printf("FAILED\n\n");
                }
            }
            else {
                waitpid(pid, &status, WNOHANG);
                printf("[%d] child process end %d\n", getpid(), pid);
                printf("SUCCESS\n\n");
            }
        }
    }
    return 0;
}

