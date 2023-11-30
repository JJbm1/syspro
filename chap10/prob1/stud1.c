#include <stdio.h>   
#include <stdlib.h>

struct student {
    int id;
    char name[20];
};

int main(){
    struct student *ptr;
    int n, i;

    printf("How many students do you want to enter? ");
    scanf("%d", &n);
    if (n <= 0) {
        fprintf(stderr, "Error:You entered the wrong number of students.\n");
        fprintf(stderr, "Exit the program.\n");
        exit(1);
    }
	 ptr = (struct student *) malloc(n * sizeof(struct student));
	 if (ptr == NULL) {
	     perror("malloc"); 
                  exit(2);
	 }
	
	 printf("Please enter %d's student ID number and name.\n", n);
	 for (i = 0; i < n; i++)
          scanf("%d %s", &ptr[i].id, ptr[i].name);
	
	 printf("\n* Student Information (Reverse Order) *\n");
	 for (i = n - 1; i >= 0; i--)
	      printf("%d %s\n", ptr[i].id, ptr[i].name);
	
	 printf("\n");
	 exit(0);
}

