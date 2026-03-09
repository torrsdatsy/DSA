#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


int main() {
    struct node *head, *second, *third, *temp;
    int count = 0;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = head;

    temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }while(count < 5);
    
    return 0;
}