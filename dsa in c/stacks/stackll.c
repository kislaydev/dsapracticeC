#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * top = NULL;
void pushiab(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    if(top == NULL){
        top = newnode;
    }
    else{
        struct node * temp = top;
        newnode -> next = temp;
        top = newnode;
    }
}
void popdab(){
    if(top == NULL){
        printf("Stack underflow");
    }
    else{
        struct node * temp = top;
        printf("Popped item is : %d", temp -> data);
        top = temp -> next;
        free(temp); 
    }
}
void display(){
    struct node * temp = top;
    if(top == NULL){
        printf("Stack Underflow");
    }
    else{
        while(temp != NULL){
            printf("%d \n", temp -> data);
            temp = temp -> next;
        }
    }
}
void peek(){
    if(top == NULL){
        printf("Empty Stack");
    }
    else{
        printf("Top element is : %d", top -> data);
    }
}
int main(){
    int choice, num;

    while(1){
        printf("\n===== STACK (LINKED LIST) MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &num);
                pushiab(num);
                break;

            case 2:
                popdab();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}