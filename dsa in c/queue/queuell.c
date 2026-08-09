#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;
void enqueue(int x){
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
    }
}
void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue Underflow");
    }
    else if(front == rear){
        printf("Dequeued element is %d", front -> data);
        struct node * temp = front;
        front = rear = NULL;
        free(temp);
    }
    else{
        printf("Dequeued element is %d", front -> data);
        struct node * temp = front;
        front = front -> next;
        free(temp);
    }
}
void peek(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty");
    }
    else{
        printf("front element is %d", front -> data);

    }
}
void display(){
    if(front == NULL && rear == NULL){
        printf("Empty queue");
    }
    else{
        struct node * temp = front;
        while(temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
}
int main(){
    enqueue(5);
    enqueue(6);
    enqueue(22);
    enqueue(1);
    display();
    dequeue();
    dequeue();
    peek();
    display();
}