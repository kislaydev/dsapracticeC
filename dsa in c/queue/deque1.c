#include<stdio.h>
#define N 5
int dq[N];
int front = -1, rear = -1;
void enqueuefront(int x){
    if((front == 0 && rear == N-1) || (front == rear +1)){
        printf("queue overflow");
    }    
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        dq[front] = x;
    }
    else if(front == 0){
        front = N-1;
        dq[front] = x;
    }
    else{
        front --;
        dq[front] = x;
    }
}
void enqueuerear(int x){
    if((front == 0 && rear == N-1) || (front == rear +1)){
        printf("queue overflow");
    }
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        dq[rear] = x;
    } 
    else if(rear == N-1){
        rear = 0;
        dq[rear] = x;
    }
    else{
        rear++;
        dq[rear] = x;
    }
}
void dequeuefront(){
    if(front == -1 && rear == -1){
        printf("Queue underflow");
    }
    else if(front == rear){
        printf("Dequeued element is %d", dq[front]);
        front = rear = -1;
    }
    else if(front == N-1){
        printf("Dequeued element is %d", dq[front]);
        front = 0;
    }
    else{
        printf("Dequeued element is %d", dq[front]);
        front++;
    }
}
void dequeuerear(){
    if(front == -1 && rear == -1){
        printf("Queue underflow");
    }
    else if(front == rear){
        printf("Dequeued element is %d", dq[rear]);
        rear = front = -1;
    }
    else if(rear == 0){
        printf("Dequeued element is %d", dq[rear]);
        rear = N - 1;
    }
    else{
        printf("Dequeued element is %d", dq[rear]);
        rear--;
    }
}