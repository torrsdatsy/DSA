#include<stdio.h>
#include<stdlib.h>

// structure declaration
struct node {
    int data;
    struct node *next;
};

// function to create the nodes.
struct node* createNode(int value) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// circular linked list implementation

int main () {
    struct node *head = NULL, *temp = NULL, *newnode;
    int value, n, choice;

    // enetering the number of nodes.
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    do{
        printf("\n1. Enter the value of nodes\n");
        printf("2. Display the nodes\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert at any position\n");
        printf("6. Delete at the beginning\n");
        printf("7. Delete at the end\n");
        printf("8. Delete at any position\n");
        printf("9. EXIT\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("");
                break;
            case 2:
                printf("");
                break;
            case 3:
                printf("");
                break;
            case 4:
                printf("");
                break;
            case 5:
                printf("");
                break;
            case 6:
                printf("");
                break;
            case 7:
                printf("");
                break;
            case 8:
                printf("");
                break;
            case 9:
                printf("Exiting the program... \n");
                printf("THANK YOU! \n");
                break;
            default:
                printf("Invalid, Try Again! \n");
        }
    } while(choice != 9);
    return 0;
}