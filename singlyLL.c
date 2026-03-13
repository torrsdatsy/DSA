#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enterNodes(struct node **head, int n) {
    system("cls");
    struct node *newnode, *temp;
    int value;
    printf("Enter the node values\n\n");
    for(int i = 0; i < n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value:");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(*head == NULL){
            *head = temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf("\nNodes added successfully!\n");
}

void displayNodes(struct node *head) {
    struct node *temp = head;
    if(temp == NULL){
        printf("\nLists empty!\n\n");
        return;
    }
    printf("\nList: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertBeginning(struct node **head, int value){
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter the value at the beginning: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = *head;
    *head = newnode;

    printf("\n%d inserted at the beinning!\n", value);
}

void insertEnd(struct node **head, int value) {
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter the value at the end: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
    }else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("\n%d inserted at the end!\n", value);
}

void insertPosition(struct node **head, int value, int position){
    struct node *temp, *newnode;
    

    printf("\nEnter a value to insert at any position: ");
    scanf("%d", &value);
    printf("Position: ");
    scanf("%d", &position);

    if(position == 1){
        insertBeginning(head, value);
        return;
    }

    temp = *head;
    for(int i = 1; i < position - 1; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\nPosition out of range!\n");
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;

    printf("\n%d inserted at position %d\n", value, position);
}

void deleteBeginning(struct node **head) {
    if(*head == NULL){
        printf("\nList empty!\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("\nFirst node deleted successfully!\n");
}

void deleteEnd(struct node **head){
    if (*head == NULL){
        printf("\nLists empty!\n");
        return;
    } 

    struct node *temp = *head;

    
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("\nLast and only one node has been deleted!\n");
        return;
    }

    
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    
    free(temp->next);   
    temp->next = NULL;  
    printf("\nLast node deleted sucessfully!\n");
}

void deletePosition(struct node **head){
    if(*head == NULL){
        printf("\nLists empty!\n");
        return;
    }
    struct node *target, *temp = *head;
    int position;
    printf("Enter the position nodes to delete: ");
    scanf("%d", &position);

    if(position == 1){
        temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("\nNode at position 1 deleted!\n");
        return;
    }

    
    for(int i = 1; temp != NULL && i < position -1; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("\nPosition out of range!\n");
        return;
    }

    target = temp->next;
    temp->next = target->next;
    free(target);
    printf("\nNode at postition %d deleted successfully!", position);
}

int main () {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, value, choice, position;
    
    do{
        printf("\n-------Singly Linked List Menu--------\n");
        printf("\n1. Enter the values of the nodes\n");
        printf("2. Display the nodes\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert at a specific position\n");
        printf("6. Delete at the beginning\n");
        printf("7. Delete at the end.\n");
        printf("8. Delete at position.\n");
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
                deletePosition(&head);
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