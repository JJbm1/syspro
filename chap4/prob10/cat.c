#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "How to use : %s FileName\n", argv[0]);
        return 1;
    }

    int line = 0;
    int index = 1;

    if (argc > 2 && strcmp(argv[1], "-n") == 0) {
        line = 1;
        index = 2;
    }

    for (int i = index; i < argc; ++i) {
        FILE *fp;

        if (i == 1 && argc == 2) {
            fp = stdin;
        } else {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error Open File\n");
                continue;  
            }
        }

        int c;
        int num = 1;
        int line_empty = 1;

        while ((c = getc(fp)) != EOF) {
            if(line && line_empty) {
                printf("  %d ", num++);
                line_empty = 0;
            }

            putchar(c);

            if (c == '\n') {
                line_empty = 1;
            }
        }

        if (fp != stdin) {
            fclose(fp); 
        }
    }

    return 0;
}

