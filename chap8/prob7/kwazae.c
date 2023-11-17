#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
int main(int argc, char *argv[], char *envp[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                char *env_val = getenv(argv[i + 1]);
                if (env_val)
                    printf("%s = %s\n", argv[i + 1], env_val);
                i++;
            }
	    else {
                char **env;
                for (env = envp; *env != 0; env++) {
                    printf("%s\n", *env);
                }
            }
        }
       	else if (strcmp(argv[i], "-u") == 0) {
		uid_t uid = getuid();
		uid_t euid = geteuid();
		struct passwd *pw = getpwuid(uid);
		struct passwd *epw = getpwuid(euid);
        	printf("My Realistic User ID : %d(%s)\n", getuid(), pw->pw_name);
        	printf("My Valid User ID : %d(%s)\n", geteuid(), epw->pw_name);
        }
       	else if (strcmp(argv[i], "-g") == 0) {
		gid_t gid = getgid();
		gid_t egid = getegid();
		struct group *gr = getgrgid(gid);
		struct group *egr = getgrgid(egid);
        	printf("My Realistic Group ID : %d(%s)\n", getgid(), gr->gr_name);
        	printf("My Valid Group ID : %d(%s)\n", getegid(), egr->gr_name);
        }
       	else if (strcmp(argv[i], "-i") == 0) {
            printf("my process number : [%d]\n", getpid());
        }
       	else if (strcmp(argv[i], "-p") == 0) {
            printf("my parent's process number : [%d]\n", getppid());
        }
    }
    return 0;
}

