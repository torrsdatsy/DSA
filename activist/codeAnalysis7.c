#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *second, *temp;
    int i = 0;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));

    head->data = 8;
    head->next = second;

    second->data = 16;
    second->next = head;
    temp = head;

    while(i < 4){
        printf("%d ", temp->data);
        if(temp->data == 8){
            temp->data = 80;
        }
        temp = temp->next;
        i++;
    }

    printf("\n");

    temp = head;
    while(i < 6){
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    return 0;
}