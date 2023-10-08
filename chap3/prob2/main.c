#include <stdio.h>
#include <string.h>
#include "copy.h"

typedef struct{
	char text[MAXLINE];
	int length;
}Line;

int main(){
	Line lines[MAX_LINE];
	int num	= 0;
	char input[MAXLINE];

	while(fgets(input, sizeof(input), stdin) != NULL) {
		if(input[0] == "\n"){
			break;
		}
		int i;
		for(i = 0; input[i] != '\0'; i++){
			lines[num].text[i] = input[i];
		}
		lines[num].text[i] = '\0';
		lines[num].length = i;
		num++;
	}

	for(int i = 0; i < num; i++){
		for(int j = i + 1; j < num; j++){
			if(lines[i].length < lines[j].length){
				Line temp = lines[i];
				lines[i] = lines[j];
				lines[j] = temp;
			}
		}
	}

	for(int i = 0; i < num; i++){
		printf("%s", lines[i].text);
	}
	return 0;
}
