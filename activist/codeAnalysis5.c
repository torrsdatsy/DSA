#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};


int main() {
    struct node *head, *second, *third, *temp;
    int count = 0;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = NULL;
    third->prev = second;
    
    temp = third;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    
    return 0;
}