#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * prev;
    int data;
    struct node * next;
};
struct node * head = NULL;
void insertatbeg(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode -> next = head;
        head -> prev = newnode;
        head = newnode;
    }
}
void insertatend(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        struct node * temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}
void insertatpos(int x, int pos){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> next = NULL;
    newnode -> data = x;
    newnode -> prev = NULL;
    if(head == NULL){
        head = newnode;
    }
    else if(pos == 1){
        newnode -> next = head;
        head -> prev = newnode;
        head = newnode;
    }
    else{
        struct node * temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp -> next;
        }
        temp -> next -> prev = newnode;
        newnode -> next = temp -> next;
        temp -> next = newnode;
        newnode -> prev = temp;
    }

}
void deletefrombeg(){
    if(head == NULL){
        printf("Linkedlist is empty");
    }
    else if(head -> next == NULL){
        free(head);
    }
    else{
        struct node * temp = head;
        head = head -> next;
        head -> prev = NULL;
        free(temp);
    }
}
void deletefromend(){
    if(head == NULL){
        printf("Lindedlist is empty");
    }
    else if(head -> next == NULL){
        free(head);
    }
    else{
        struct node * temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> prev -> next = NULL;
        free(temp);
    }
}
void delatpos(int pos){
    if(head == NULL){
        printf("linkedlist is empty");
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else if(pos == 1){
        struct node * temp = head;
        temp -> next -> prev = NULL;
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
    else{
        struct node * temp = head;
        struct node * temp2;
        for(int i = 1; i<pos-1; i++){
            temp = temp -> next;
        }
        temp2 = temp -> next -> next;
        free(temp -> next);
        temp -> next = temp2;
        temp2 -> prev = temp;
    }
}
void delafterpos(int pos){
    if(head == NULL){
        printf("linkedlist is empty");
    }
    else if(head -> next == NULL){
        printf("nothing to delete");
    }
    else if(pos == 1){
        struct node * temp = head;
        struct node * temp2 = temp -> next;
        temp->next->next->prev = temp;
        temp -> next = temp2 -> next;
        free(temp -> next);
    }
    else{
        struct node * temp = head;
        for(int i = 1; i<pos; i++){
            temp = temp -> next;
        }
        struct node *del = temp->next;
        temp->next = del->next;
        if(del->next != NULL){
            del->next->prev = temp;
        }
        free(del);
    }
}
void display(){
    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }

    struct node *temp = head;

    printf("List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int choice, x, pos;

    while(1){
        printf("\n----- DOUBLY LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Delete after Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertatbeg(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertatend(x);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                insertatpos(x, pos);
                break;

            case 4:
                deletefrombeg();
                break;

            case 5:
                deletefromend();
                break;

            case 6:
                delatpos(pos);
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delafterpos(pos);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}