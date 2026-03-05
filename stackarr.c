#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

int stack[MAX];
int top = -1;

// push an element into the stack.
void push(int value) {
    // check if the stack is full.
    if(top == MAX - 1) {
        printf("\nStack Overflow! \n");
        return;
    }
    stack[++top] = value; // increment top and then assign value to stack[top].
    printf("\nPushed %d into the stack successfully! \n", value);
}

// pop an element from the stack.
void pop() {
    // check if the stack is empty.
    if(top == -1) {
        printf("\nStack Underflow! \n");
        return;
    }
    stack[top--]; // decrement top after popping the element.
    printf("\nPopped out successfully! \n");
}

// peek the top element of the stack.
void peek() {
    // check if the stack is empty.
    if(top == -1) {
        printf("\nStack is empty! \n");
        return;
    }
    printf("\nTop element is %d\n\n", stack[top]);
}

// display the stack elements.
void display () {
    // check if the stack is empty.
    if(top == -1) {
        printf("\nStack is empty! \n");
        return;
    }
    // display the stack elements from top to bottom.
    printf("\nStack elements are: ");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main () {
    int choice, value;

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
                printf("\nExiting the program... \n");
                break;
            default:
                printf("\nInvalid, Try Again! \n");   
        }
    }while(choice != 5);

    return 0;
}