#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int i;

    for(i = 1; i <= 3; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = head;
        head = newnode;
    }

    temp = head;
    while(temp != NULL){
        if(temp->data % 2 == 0){
            printf("E ");
        }else {
            printf("O ");
        }
        temp = temp->next;
    }
    
    return 0;
}