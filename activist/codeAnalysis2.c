#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


int main() {
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 100;
    head->next = NULL;

    struct node *temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}