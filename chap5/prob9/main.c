#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
    char text[10][100]={'\0'};
    int fd;
    char buf;

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        write(2, "File Open Error\n", 15);
        exit(2);
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<100;j++){
            read(fd,&buf,1);
            text[i][j]=buf;
            if(buf=='\n'){
                break;
            }
            else if(buf=='.'){
                text[i][j+1]='\n';
                break;
            }
        }
    }

    for(int i=3;i>=0;i--){
        write(1,text[i],strlen(text[i]));
    }
    close(fd);
    return 0;
}
