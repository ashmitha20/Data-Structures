#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;
struct node *temp,*newnode,*prev,*next;

void insertend() {
     char ch;
    do {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d",&newnode->data);
    newnode->link = NULL;
    if(head == NULL ){
        head = newnode;
        temp = newnode;
    }
    else {
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
        newnode->link = NULL;
    }
    printf("Do you want to continue Y/N: ");
        scanf(" %c",&ch);
    }while(ch == 'Y' || ch =='y');
}
void display() {
    temp=head;
    if(head==NULL){
        printf("\nList is empty");
        return ;
        }
        while(temp != NULL) {
            printf("%d\t",temp->data);
            temp = temp->link;
        }
        }
    void copy() {
        struct node*temp2,*head2;
        temp = head;
        head2 = NULL;
        while(temp != NULL) {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = temp->data;
            newnode->link = NULL;
        
        if(head2 == NULL) {
            head2 = newnode;
            temp2 = newnode;
        }
        else {
            temp2->link = newnode;
            temp2 = newnode;
        }
        
        temp = temp->link;
    }
    }
    void reversal() {
        prev = 0; next = temp;
        while (next != NULL) {
            next = next->link;
            temp->link = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }
    void main() {
        insertend();
        display();
        copy();
        reversal();
        display();
    }