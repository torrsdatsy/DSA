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
void deleteBeginning(struct node **head);
void deleteEnd(struct node **head);
void deletePosition(struct node **head, int position);

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
        printf("6. Delete at beginning.\n");
        printf("7. Delete at end\n");
        printf("8. Delete at specific position\n");
        printf("9. EXIT\n");
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
                deleteBeginning(&head);
                break;
            case 7:
                deleteEnd(&head);
                break;
            case 8:
                deletePosition(&head, position);
                break;
            case 9:
                printf("Exiting the program. \n");
                printf("THANK YOU! \n");
                break;
            default:
                printf("Invalid, Try Again! \n");
        }
    }while(choice != 9);
    
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

void deleteBeginning(struct node **head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("\nFirst node deleted successfully!\n");
}

void deleteEnd(struct node **head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = *head;

    // Case 1: Only one node
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("\nLast node deleted, list is now empty!\n");
        return;
    }

    // Case 2: More than one node → traverse to last
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Adjust links
    temp->prev->next = NULL;
    free(temp);

    printf("\nLast node deleted successfully!\n");
}

void deletePosition(struct node **head, int position) {
    if(*head == NULL){
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter the position you wish to delete: ");
    scanf("%d", &position);

    struct node *temp = *head;
   

    for(int i = 1; temp != NULL && i < position; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("\nPosition out of range!\n");
        return;
    }

    if(temp->prev == NULL){
        *head = temp->next;
        if(*head == NULL) (*head)->prev = NULL;
    }else if(temp->next == NULL) {
        temp->prev->next = NULL;
    }else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("\nNode deleted at position %d successfully!", position);
}