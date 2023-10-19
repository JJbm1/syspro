#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char lines[NUM][MAXLINE];

int main(){
	int i, j;
	i = 0;
	while (i < NUM && fgets(line, MAXLINE, stdin) != NULL) {	
		copy(line, lines[i]);
		i++;
	}

	for(i = 0; i < NUM; i++){
	       for(j = i + 1; j < NUM; j++){
		       if(strlen(lines[i]) < strlen(lines[j])){
			       char temp[MAXLINE];
			       copy(lines[i], temp);
			       copy(lines[j], lines[i]);
			       copy(temp, lines[j]);
		       }
	       }
	}

	for(i = 0; i < NUM; i++){
		printf("%s", lines[i]);
	}
	return 0;
}
