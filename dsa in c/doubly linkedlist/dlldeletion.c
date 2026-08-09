#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * prev;
    int data;
    struct node * next;
};
struct node * head = NULL;
void create(){
    int choice;
    while(choice){
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode -> data);
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
            temp ->next = newnode;
            newnode -> prev = temp;
        }
        printf("Do you want to continue?");
        scanf("%d", &choice);
    }
}
void display(){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}
void delfromstart(){
    struct node * temp = head;
    if(head == NULL){
        printf("Empty list");
        return;
    }
    else if(head -> next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        struct node * temp2;
        temp2 = temp -> next;
        head = temp2;
        temp2 -> prev = NULL;
        free(temp);
    }
}
void delatend(){
    struct node * temp = head;
    if(head == NULL){
        printf("Empty list");
        return;
    }
    else if(head -> next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        struct node * temp2;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp2 = temp -> prev;
        temp2 -> next = NULL;
        free(temp);
    }
}
void deletefrompos(int pos){
    struct node * temp = head;
    struct node * len = head;
    int count = 0;
    while(len != NULL){
        len = len -> next;
        count++;
    }
    if(pos<1 || pos>count){
        printf("Invalid position");
    }
    else{
        if(head == NULL){
            printf("Empty list");
            return;
        }
        else if(head -> next == NULL){
            head = NULL;
            free(temp);
        }
        else if(pos == 1){
            head = head -> next;
            if(head != NULL){
                head ->prev = NULL;
            }
            free(temp);
            return;
        }
        else{
            struct node * temp2;
            struct node * temp3;
            for(int i = 0; i<pos-1; i++){
                temp = temp->next;
            }
            temp2 = temp -> next;
            temp3 = temp -> prev;
            temp3 -> next = temp2;
            temp2 -> prev = temp3;
            free(temp);
        }
    }
}
int main(){
    int pos;

    printf("=== Create List ===\n");
    create();

    printf("\nInitial List:\n");
    display();

    // 🔹 Delete from start
    printf("\nDelete from start:\n");
    delfromstart();
    display();

    // 🔹 Delete from end
    printf("\nDelete from end:\n");
    delatend();
    display();

    // 🔹 Delete from position (middle)
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    deletefrompos(pos);
    display();

    // 🔹 Edge case: delete from start again
    printf("\nDelete from start again:\n");
    delfromstart();
    display();

    // 🔹 Edge case: delete until empty
    printf("\nDeleting all nodes:\n");
    while(head != NULL){
        delfromstart();
        display();
        printf("---\n");
    }

    // 🔹 Try deleting from empty list
    printf("\nTry delete from empty list:\n");
    delfromstart();
    delatend();
    deletefrompos(1);

    return 0;
}