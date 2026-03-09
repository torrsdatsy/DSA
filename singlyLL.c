#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enterNodes(struct node **head, int n) {
    struct node *newnode, *temp;
    int value;
    for(int i = 0; i < n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter value:");
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
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main () {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, value, choice;
    
    do{
        printf("\n-------Singly Linked List Menu--------\n");
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
                //insertBeginning(&head, value);
                break;
            case 4:
                //insertEnd(&head, value);
                break;
            case 5:
                //insertPosition(&head, value, position);
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