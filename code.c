#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, value,pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    // Display
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    printf("\n");
    // Display
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    temp = head;
    for(int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}