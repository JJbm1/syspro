#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node *top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = top->next;
    top->next = newNode;
}

int pop(struct node *top) {
    struct node *temp = top->next;
    int data = temp->data;

    top->next = temp->next;
    free(temp);

    return data;
}

void printStack(struct node *top) {
    while (top->next != NULL) {
        printf("%d ", top->next->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct node *top = (struct node *)malloc(sizeof(struct node));

    top->next = NULL;

    while (1) {
        int value;
        if (scanf("%d", &value) != 1) {
            printf("Print stack\n");
            break;
        }
        push(top, value);
    }

    while (top->next != NULL) {
        int value = pop(top);
        printf("%d\n", value);
    }
    free(top);
    return 0;
}
