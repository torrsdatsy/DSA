#include<stdio.h> // code analysis #1
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    struct node *head, *second;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;
    head->prev = NULL;

    second->data = 22;
    second->next = NULL;
    second->prev = head;

    struct node *temp = head;
    while(temp != NULL) {
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}