#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    struct node * prev;
    int data;
    struct node * next;
};
struct node *head = NULL;
void create(){
    int choice;
    while(choice){ 
        struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode -> next = NULL;
        newnode -> prev = NULL;
        struct node * temp = head;
        if(head == NULL){
            head = newnode;
        }
        else{
            while(temp->next != NULL){
            temp = temp->next;
            }
            newnode->prev = temp;
            temp->next = newnode;
        }
        printf("Do you want to continue?");
        scanf("%d",&choice);
     }
}
void display(){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d \n", temp -> data);
        temp = temp -> next;
    }
}
int main(){
    create();
    display();
    getch();
}
