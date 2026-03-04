#include<stdio.h>
#include<stdlib.h>

//structure declaration
struct node {
    int data;
    struct node *prev;
    struct node *next;
};


// function prototypes.
void enterNodes(struct node **head, int n);
void displayNodes(struct node *head);
void insertBeginning(struct node **head, int value);
void insertEnd(struct node **head, int value);
void insertPosition(struct node **head, int value, int position);

int main () {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, value, position, choice;


    do{
        printf("\n-------Doubly Linked List Menu--------\n");
        printf("\n1. Enter the values of the nodes\n");
        printf("2. Display the nodes\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert at a specific position\n");
        printf("6. EXIT\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of nodes: ");
                if(scanf("%d", &n) != 1) n = 0;
                head = NULL; 
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
                printf("Exiting the program. \n");
                printf("THANK YOU! \n");
                break;
            default:
                printf("Invalid, Try Again! \n");
        }
    }while(choice != 6);
    
    return 0;
}

// function to enter the values.
void enterNodes(struct node **head, int n) {
    struct node *temp = NULL, *newnode;
    int value;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter values of node %d: ", i+1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        // traversing the list.
        if(*head == NULL) {
            *head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

}

// function to display the nodes.
void displayNodes(struct node *head) {
    struct node *temp = head;



    // display traversing list.
    if(temp == NULL) {
        printf("\nList is empty! \n");
    }else {
        printf("\n");
        while(temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// function to insert at the beginning.
void insertBeginning(struct node **head, int value) {
    struct node *newnode = NULL;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Please enter to inser at the beginning: ");
    scanf("%d", &value);

    
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = *head;
    *head = newnode;


}

// function to insert at the end.
void insertEnd(struct node **head, int value) {
    struct node *newnode = NULL, *temp = NULL;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Please enter to insert at the end: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(*head == NULL) {
        *head = newnode;
    } else {
        temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// function to insert at any position.
void insertPosition(struct node **head, int value, int position) {
    struct node *newnode = NULL, *temp = NULL;
    //newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nPlease enter the value to insert: ");
    scanf("%d", &value);
    printf("\nEnter the position to insert: ");
    scanf("%d", &position);

    //newnode->data = value;

    if(position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;

    for(int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("\nPosition out of range! \n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    

}