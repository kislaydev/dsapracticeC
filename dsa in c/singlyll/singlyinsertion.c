#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * head = NULL;
void insertatbeg(int x){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode -> next = head;
        head = newnode;
    }
}
void insertatend(int x){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        struct node * temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}
void insertatpos(int x, int pos){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else if(pos == 1){
        newnode -> next = head;
        head = newnode;
    }
    else{
        struct node * temp = head;
        for(int i = 1; i<pos-1; i++){
            temp = temp -> next;
        }
        if(temp == NULL){
            printf("invalid position");
        }
        else{
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
    }
}
void deleteatfront(){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else{
        struct node * temp = head;
        head = temp->next;
        free(temp);
    }
}
void deleteatend(){
    if(head == NULL){
        printf("Linkedlist is empty");
    }
    else if(head -> next == NULL){
        free(head);
    }
    else{
        struct node * temp = head;
        struct node * temp2;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        temp2 = temp->next;
        free(temp2);
    }
}
void deleteatpos(int pos){
    if(head == NULL){
        printf("linked list is empty");
    }
    else if(pos == 1){
        struct node * temp = head;
        head = head -> next;
        free(temp);
    }
    else if(head -> next == NULL){
        head = NULL;
    }
    else{
        struct node * temp = head;
        struct node * temp2;
        for(int i = 1; i<pos-1; i++){
            temp = temp -> next;
        }
        temp2 = temp -> next;
        temp -> next = temp2->next;
        temp2 -> next = NULL;
        free(temp2);
    }
}
void display(){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else{
        struct node * temp = head;
        while(temp != NULL){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}
int main(){
    int choice, x, pos;

    while(1){
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertatbeg(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertatend(x);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                insertatpos(x, pos);
                break;

            case 4:
                deleteatfront();
                break;

            case 5:
                deleteatend();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteatpos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}