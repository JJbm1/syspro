#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        return -1;
    }

    struct node *temp = *head;
    int del_Data = temp->data;

    *head = (*head)->next;
    free(temp);

    if (*head == NULL) {
        *tail = NULL;
    }

    return del_Data;
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;

    int value;
    
    while (scanf("%d", &value) == 1) {
        addq(&head, &tail, value);
    }

    int del_Value;
    printf("Print queue\n");
    while ((del_Value = delete(&head, &tail)) != -1) {
        printf("%d\n", del_Value);
    }

    return 0;
}

