#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node * next;
};
struct node * head = NULL;
void enqueue(int x, int p){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> priority = p;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else if(newnode -> priority > head -> priority){
        newnode -> next = head;
        head = newnode;
    }
    else{
        struct node * temp = head;
        while(temp -> next != NULL && temp -> next -> priority > newnode -> priority){
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;

    }
}
void dequeue(){
    if(head == NULL){
        printf("Queue Underflow");
    }
    else{
        printf("Dequeued element is %d", head -> data);
        struct node * temp = head;
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
}