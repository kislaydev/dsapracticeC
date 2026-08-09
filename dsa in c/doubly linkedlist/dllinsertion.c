#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    struct node * prev;
    int data;
    struct node * next;
};
struct node * head = NULL;
void create(){
    int choice;
    while(choice){
        struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
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
            newnode -> prev = temp;
            temp -> next = newnode;
        }
        printf("Do you want to continue?");
        scanf("%d", &choice);
    }
}
struct node * createonenewnode(){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}
void display(){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void insertatend(){
    struct node * newnode = createonenewnode();
    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        struct node *temp = head;
        while(temp ->next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}
void insertatstart(){
    struct node * newnode = createonenewnode();
    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        struct node * temp = head;
        head = newnode;
        temp -> prev = newnode;
        newnode -> next = temp;   
    }
}
void insertatpos(int pos){
    int count = 0;
    struct node * len = head;
    while(len != NULL){
        len = len -> next;
        count ++;
    }
    if(pos < 1 || pos > count + 1){
        printf("Position invalid");
        return;
    }
    else if(pos == 1){
        insertatstart();
    }
    else if(pos == count+1){
        insertatend();
    }
    else{
        struct node * newnode = createonenewnode();
        struct node * temp2 = head;
        for(int i = 1; i<pos; i++){
            temp2 = temp2 -> next;
        }
        struct node * temp = temp2 -> prev;
        temp -> next = newnode;
        newnode ->prev = temp;
        newnode -> next = temp2;
        temp2 -> prev = newnode;
        
    }
}
void insertafterpos(int pos){
    int count = 0;
    struct node * len = head;
    while(len != NULL){
        len = len->next;
        count ++;
    }
    if(pos > count){
        printf("invalid position");
    }
    else if(pos == 0){
        insertatstart();
    }
    else if(pos == count){
        insertatend();
    }
    else{
        struct node * newnode = createonenewnode();
        struct node * temp = head;
        for(int i = 0; i<pos; i++){
            temp = temp-> next;
        }
        struct node * temp2 = temp -> prev;
        newnode -> prev = temp2;
        newnode -> next = temp;
        temp2 -> next = newnode;
        temp -> prev = newnode;
    }
}

int main(){
    int choice, pos;
    while(1){
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Start\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Insert After Position\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create();
                break;

            case 2:
                printf("List elements:\n");
                display();
                break;

            case 3:
                insertatstart();
                break;

            case 4:
                insertatend();
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                insertatpos(pos);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                insertafterpos(pos);
                break;

            case 0:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}