// implementing stack using linked list.
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

// structure declaration.
struct node {
    int data;
    struct node * next;
};

struct node *top = NULL;

// push an element into stack.
void push(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("\nStack Overflow\n\n"); // 
        return;
    }

    // assign the values.
    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("\n%d pushed into stack.\n\n", value);
}

// pop an element from stack
void pop() {
    if(top == NULL){
        printf("\nStack Underflow\n\n");
        return;
    }
    
    struct node *temp = top;
    printf("\n%d popped from stack\n\n", temp->data);
    top = top->next;
    free(temp);
}

// peek the top element
void peek() {
    if(top == NULL){
        printf("\nStack is empty!\n\n");
        return;
    }
    printf("\nTop element: %d\n\n", top->data);
}

// display an element.
void display() {
    if(top == NULL){
        printf("\nStack is empty!\n\n");
        return;
    }
    struct node *temp = top;
    printf("\nStack from top to bottom: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    
}


int main () {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int n, value, choice;

    do{
        printf("------------------Stack Implementation------------------\n");
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. EXIT\n");
        printf("\nSelect your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting the program... \n\n");
                break;
            default:
                printf("\nInvalid, Try Again! \n\n");   
        }
    }while(choice != 5);
    return 0;
}