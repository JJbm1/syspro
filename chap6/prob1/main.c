#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int i;
	struct stat buf;
	for(i = 1; i < argc; i++){
		printf("%s : ", argv[i]);
		if(lstat(argv[i], &buf) < 0){
			perror("lstat()");
			continue;
		}

		if(S_ISREG(buf.st_mode)) printf("%s \n", "File");
		if(S_ISDIR(buf.st_mode)) printf("%s \n", "Directory");
	        if(S_ISCHR(buf.st_mode)) printf("%s \n", "Text Device File");
		if(S_ISBLK(buf.st_mode)) printf("%s \n", "Block Device File");
		if(S_ISFIFO(buf.st_mode)) printf("%s \n", "FIFO File");
		if(S_ISLNK(buf.st_mode)) printf("%s \n", "Symbolic Link");
		if(S_ISSOCK(buf.st_mode)) printf("%s \n", "Socket");
	}
	exit(0);
}	
