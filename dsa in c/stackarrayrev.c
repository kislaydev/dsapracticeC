#include<stdio.h>
#define N 10
int stack[N];
int top = -1;
int isempty(){
    if(top == -1){
        printf("Stack Empty");
    }
}
int isfull(){
    if(top == N-1){
        printf("Stack is full");
    }
}
void push(int x){
    if(top == N-1){
        printf("Stack overflow");
    }
    else{
        top++;
        stack[top] = x;
    }
}
void pop(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        printf("Popped element is %d", stack[top]);
        top--;
    }
}
void peek(){
    if(top == -1){
        printf("Stack is empty");
    }
    else{
        printf("Top element is %d", stack[top]);
    }
}
void display(){
    if(top == -1){
        printf("Stack Empty");
    }
    else{
        for(int i = top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}
void main(){
    isempty();
    push(9);
    push(2);
    push(5);
    push(20);
    display();
    isempty();
    isfull();
    pop();
    pop();
    display();    
} 