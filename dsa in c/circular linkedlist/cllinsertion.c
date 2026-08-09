#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * tail = NULL;
void create(){
    int choice;
    while(choice){
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode -> data);
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
        printf("DO you want to continue?");
        scanf("%d", &choice);
    }
}
void display(){
    if(tail == NULL){
        printf("Empty List");
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
struct node * createonenewnode(){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    return newnode;
}
void insertatbeg(){
    struct node * newnode = createonenewnode();
    if(tail == NULL){
        tail = newnode;
        newnode -> next = tail;
    }
    else{
        struct node * temp = tail -> next;
        tail -> next = newnode;
        newnode -> next = temp;
    }
}