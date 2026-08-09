#include<stdio.h>
#define N 5
int stack[N];
int top = -1;
void push(int num){
    if(top == N-1){
        printf("Overflow");    
    }
    else{
        top++;
        stack[top] = num;
    }
}
void pop(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        printf("Popped item is : %d", stack[top]);
        top--;
    }
}
void peek(){
    if(top == -1){
        printf("Empty Stack");
    }
    else{
        printf("%d", stack[top]);
    }
}
void display(){
    for(int i = top; i>=0; i--){
        printf("%d  ", stack[i]);
    }
}
void main(){
    int ch;
    while(ch != 0){
        printf("Enter choice : 1-Push, 2-Pop, 3-Peek, 4-Display");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter element to be pushed");
                    int x;
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            default: printf("Invalid Choice");
        }
    }
}