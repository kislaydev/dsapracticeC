#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * top = NULL;
void isempty(){
    if(top == NULL){
        printf("Stack Empty");
    }
}
void push(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode -> next = top;
        top = newnode;
    }
}
void pop(){
    if(top == NULL){
        printf("Stock Underflow");
    }
    else{
        struct node * temp = top;
        printf("popped item is %d", top->data);
        top = top -> next;
        free(temp);
    }
}
void peek(){
    if(top == NULL){
        printf("Stack empty");
    }
    else{
        printf("Top element is %d", top->data);
    }
}
void display(){
    if(top == NULL){
        printf("Stack Empty");
    }
    else {
        struct node * temp = top;
        while(temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
}
void main(){
    int choice, x;

    while(1){
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isempty();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

}