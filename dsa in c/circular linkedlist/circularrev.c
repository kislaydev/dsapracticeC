#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * head = NULL;
void insertatbeg(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
        newnode->next = head;
    }
    else{
        struct node * temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = head;
        head = newnode;
    }
}
void insertatend(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
        newnode -> next = head;
    }
    else{
        struct node * temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = head;
    }
}
void insertatpos(int x, int pos){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
        newnode -> next = head;
    }
    else if(pos == 1){
        struct node * temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        newnode -> next = head;
        head = newnode;
        temp -> next = newnode;
    }
    else{
        struct node * temp = head;
        struct node * temp2;
        for(int i = 1; i<pos-1; i++){
            temp = temp -> next;
        }
        if(temp -> next -> next == head){
            temp2 = temp -> next;
            temp2 -> next = newnode;
            newnode -> next = head;
        }
        else{
            temp2 = temp -> next;
            temp -> next = newnode;
            newnode -> next = temp2;
        }
    }
}
void delfrombeg(){
    if(head == NULL){
        printf("Linkedlist is empty");
    }
    else{
        struct node * temp = head;
        struct node * temp2 = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        head = head -> next;
        temp -> next = head;
        free(temp2);
    }
}
void delfromend(){
    if(head == NULL){
        printf("Linkedlist is empty");
    }
    else{
        struct node * temp = head;
        struct node * temp2 = head;
        while(temp -> next -> next != head){
            temp = temp -> next;
        }
        temp2 = temp -> next;
        temp -> next = head;
        temp2 -> next = NULL;
        free(temp2);
    }
}
void delfrompos(int pos){
    if(head == NULL){
        printf("linkedlist is empty");
    }
    else{
        struct node * temp = head;
        for(int i = 1; i<pos-1; i++){
            temp = temp -> next;
        }
        struct node * temp2 = temp -> next;
        temp -> next = temp2-> next;
        temp2->next = NULL;
        free(temp2);
    }
}
void display(){
    struct node * temp = head;
    while(temp -> next != head){
        printf("%d ", temp-> data);
        temp = temp -> next;
    }
    printf("%d", temp -> data);
}