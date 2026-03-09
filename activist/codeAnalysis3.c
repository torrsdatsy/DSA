#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


int main() {
    struct node *head = NULL, *newnode, *temp;
    int i;

    for(i = 1; i <=4; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i * 100;
        newnode->next = head;
        head = newnode;
    }

    temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%d ->", temp->data);
        if(temp->data == 200){
            temp->data = 2000;
        }
        temp = temp->next;
    }

    temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}