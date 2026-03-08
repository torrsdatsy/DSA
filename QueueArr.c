#include<stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

// function 
int isFull() {
    return (rear == SIZE - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is full.\n\n");
        return;
    }
    
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("\n%d inserted into queue.\n\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is empty\n\n");
        return;
    }
    
    printf("\n%d removed from queue.\n\n", queue[front]);
    front++;
}

void peek() {
    if (isEmpty()){
        front = rear = -1;
        printf("\nQueue is empty!\n\n");
        return;
    }
    printf("\nFront Element: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty!\n\n");
        return;
    }
    printf("\nQueue Elements front <- rear\n\n");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n\n");
}

int main () {
    int choice, value;

    do {
        printf("---------------------Queue Operation (Array)--------------------\n");
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPlease enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting the program....\n");
                break;
            default:
                printf("\nInvalid input!");
        } 
    } while (choice != 5);

    return 0;
}