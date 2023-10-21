#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLine 1000
#define MaxLength 1000

int main() {
    FILE* file = fopen("test.txt", "r");
    if (file == NULL){
        perror("File Open Error");
        return 1;
    }

    char text[MaxLine][MaxLength];
    int line = 0;

    while(fgets(text[line], MaxLength, file) != NULL) {
        text[line][strcspn(text[line], "\n")] = '\0'; 
        line++;
    }

    fclose(file);

    printf("File read success\n");
    printf("Total Line : %d\n", line);
    printf("You can choose 1 ~ %d Line or *\n", line);
    printf("Please enter the line to select: ");

    char input[256];
    fgets(input, sizeof(input), stdin); 
    input[strcspn(input, "\n")] = '\0'; // 입력된 문자열에서 첫 번째 개행 문자('\n')가 나타나는 위치를 찾아 해당 위치에 널('\0') 문자를 삽입하는 코드
					// strcspn(input, " ") 함수는 input 문자열에서 "\n" (개행 문자)을 찾아서 처음으로 발견된 위치의 인덱스를 반환
	if (strcmp(input, "*") == 0) { 
		for (int i = 1; i <= line; i++)
			printf("%s\n", text[i - 1]);
	}
	else {
		int start, end;
		if (sscanf(input, "%d-%d", &start, &end) == 2 && start >= 1 && end <= line && start <= end) {
			for (int i = start; i <= end; i++)
				printf("%s\n", text[i - 1]);
		}
		else {
			int index = 0;
			while (input[index] != '\0') {
				if (input[index] >= '1' && input[index] <= '9') {
					int num = input[index] - '0';
					if(num >= 1 && num <= line)
						printf("%s\n", text[num-1]);
				}
				index++;
			}
		}
	}

	return 0;
}

