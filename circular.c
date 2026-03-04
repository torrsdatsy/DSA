#include<stdio.h>
#include<stdlib.h>

// structure declaration
struct node {
    int data;
    struct node *next;
};

// function declaration.
struct node* createNode(int value);
void enterNodes(struct node **head, int n);
void displayNodes(struct node *head);
void insertBeginning(struct node **head, int value);
void insertEnd(struct node **head, int value);
void insertPosition(struct node **head, int value, int position);

// circular linked list implementation

int main () {
    struct node *head = NULL, *temp = NULL, *newnode;
    int value, n, choice, position;

    // enetering the number of nodes.
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    do{
        printf("\n-----------------Circular Linked List---------------------\n");
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
                enterNodes(&head, n);
                break;
            case 2:
                displayNodes(head);
                break;
            case 3:
                insertBeginning(&head, value);
                break;
            case 4:
                insertEnd(&head, value);
                break;
            case 5:
                insertPosition(&head, value, position);
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

// function to create the nodes.
struct node* createNode(int value) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// function to enter the values of nodes.
void enterNodes(struct node **head, int n) {
    struct node *temp = NULL, *newnode;
    int value;

    for(int i = 0; i < n; i++) {
        printf("\nEnter values: ");
        scanf("%d", &value);

        newnode = createNode(value);

        // traversing the list.
        if(*head == NULL) {
            *head = newnode;
            newnode->next = *head;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->next = *head;
            temp = newnode;
        }
    }
}

// function to display the nodes.
void displayNodes(struct node *head) {
    if(head == NULL) {
        printf("\n List is empty! \n");
        return;
    }

    struct node* temp = head;

    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head && temp != NULL);

    printf("(back to head)\n");

}

// function to insert at the beginning.
void insertBeginning(struct node **head, int value) {
    printf("\nEnter the value to insert at the beginning: ");
    scanf("%d", &value);

    struct node *newnode = createNode(value);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;
    *head = newnode;

    printf("\nNode inserted at the beginning successfully! \n");
}

// function to insert at the end.
void insertEnd(struct node **head, int value) {
    printf("\nEnter the value to insert at the end: ");
    scanf("%d", &value);

    struct node *newnode = createNode(value);

    if(*head == NULL) {
        *head = newnode;
        newnode->next = *head;
        return;
    }

    struct node *temp = *head;
    while(temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;

    printf("\nNode inserted at the end successfully! \n");
}

// function to insert a newnode at any position.
void insertPosition(struct node **head, int value, int position) {
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);
    printf("\nEnter position to insert: ");
    scanf("%d", &position);

    if(position == 1) {
        insertBeginning(head, value);
        return;
    }

    struct node *newnode = createNode(value);
    struct node *temp = *head;

    for(int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("\nNode inserted at position %d successfully! \n", position);
}