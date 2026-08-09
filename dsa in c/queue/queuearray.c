#include<stdio.h>
int front = -1;
int rear = -1;
void enqueue(int queue[], int x, int n){
    if(rear >= n-1){
        printf("Queue overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[0] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}
void dequeue(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue underflow");
    }
    else if(front == rear){
        printf("Dequeued element is %d", queue[front]);
        front++;
        front = rear = -1;
    }
    else{
        printf("Dequeued element is %d", queue[front]);
        front++;
    }
}
void peekorfront(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        printf("Element at front is %d", queue[front]);
    }
}
void display(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        for(int i = front; i<= rear; i++){
            printf("%d ",queue[i]);
        }
    }
}
int main(){
    int n;
    printf("Enter size of queue : ");
    scanf("%d", &n);
    int queue[n];
    enqueue(queue, 5,n);
    enqueue(queue, 6,n);
    enqueue(queue, 22,n);
    enqueue(queue, 1,n);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    peekorfront(queue);
    display(queue);
    return 0;
}