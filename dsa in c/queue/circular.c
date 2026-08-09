#include<stdio.h>
# define N 5
int queue[N];
int front = -1, rear = -1; 
void enqueue(int x){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = x;
    }
    else if(front == ((rear+1)%N)){
        printf("Queue overflow");
    }
    else{
        rear = (rear +1)%N;
        queue[rear] = x;
    }
}
void dequeue(){
    if(rear == -1 && front == -1){
        printf("queue underflow");
    }
    else if(front == rear){
        printf("Dequeued item is %d", queue[front]);
        rear = front = -1;
    }
    else{
        printf("Dequeued item is %d", queue[front]);
        front = (front + 1)%N;
    }
}
void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        printf("Element at front is %d", queue[front]);
    }
}
void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("queue is empty");
    }
    else{
        while(i != rear){
            printf("%d ", queue[i]);
            i = (i+1)%N;
        }
        printf("%d ", queue[rear]);
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();   // expect full queue

    dequeue();
    dequeue();

    display();   // after removing 2 elements

    enqueue(60);
    enqueue(70); // wrap-around test

    display();   // circular behavior check

    peek();

    return 0;
}