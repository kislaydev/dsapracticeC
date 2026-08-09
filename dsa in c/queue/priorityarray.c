#include<stdio.h>
#define N 5
int queue[N];
int front = -1, rear = -1;
void enqueue(int x){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = x;
    }
    else if(rear == N-1){
        printf("Queue overflow");
    }
    else{
        rear++;
        queue[rear] = x;
    }
}
//Acsending queue
/*
void dequeue(){
    if(front == -1 && rear == -1){
        printf("queue underflow");
    }
    else if(front == rear){
        printf("Item dequeued %d", queue[front]);
        front = rear = -1;
    }
    else{
        int min = queue[front];
        int ind = front;
        for(int i = front; i<=rear; i++){
            if(queue[i]<min){
                min = queue[i];
                ind = i;
            }
        }
        printf("Dequeued element is %d", min);
        for(int i = ind; i<rear; i++){
            queue[i] = queue[i+1];
        }
        rear--;
    }
}
*/
// Descending queue
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue underflow");
    }
    else if(front == rear){
        printf("Dequeued element %d ",queue[front]);
        front = rear = -1;
    }
    else{
        int ind = front, max = queue[front];
        for(int i = front; i<= rear; i++){
            if(queue[i]>max){
                max = queue[i];
                ind = i;
            }
        }
        printf("Dequeued item is %d", max);
        for( int i = ind; i<rear; i++){
            queue[i] = queue[i+1];
        }
        rear--;
    }
}
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        for(int i = front; i<= rear; i++){
            printf("%d ",queue[i]);
        }
    }
}