#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * head = NULL;
void create(){
    int choice;
    while(choice){
        struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode -> next = NULL;
        if(head == NULL){
            head = newnode;
            newnode -> next = head;
        }
        else{
            struct node * tail = head;
            while(tail -> next != head){
                tail = tail -> next;
            }
            tail -> next = newnode;
            newnode -> next = head;
        }
        printf("Do you want to continue?");
        scanf("%d",&choice);
    }
}
void display(){
    if(head == NULL){
        printf("List empty");
    }
    else{
        struct node * tail = head;
        while(tail -> next != head){
            printf("%d\n", tail -> data);
            tail = tail -> next;
        }
        printf("%d\n", tail -> data);
    }
}
int main() {
    int choice;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);

    return 0;
}