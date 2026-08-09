#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct  node * next;
};
struct node * tail = NULL;
void create(){
    int choice;
    while(choice){
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data :");
        scanf("%d", &newnode->data);
        newnode -> next = NULL;
        if(tail == NULL){
            tail = newnode;
            newnode -> next = tail;
        }
        else{
            newnode -> next = tail -> next;
            tail -> next = newnode;
            tail = newnode;
        }
        printf("Do you want to continue?");
        scanf("%d", &choice);
    }
}
void display(){
    if(tail == NULL){
        printf("Empty list");
    }
    else{
        struct node * temp = tail -> next;
        while(temp != tail){
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n", tail -> data);
    }
}
int main(){
    int ch;
    while(ch != 0){
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
                return 0;
            default:
                printf("Invalid choice\n");    
        }
    }
    return 0;
}
