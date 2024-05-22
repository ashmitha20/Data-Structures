#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;
struct node *temp,*prev;
struct node *newnode;
void creation() {
    char ch;
    do {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&(newnode->data));
        newnode->link = NULL;
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->link = newnode;
            temp = newnode;
        }
        printf("Do you want to continue Y/N: ");
        scanf(" %c",&ch);
    }while(ch =='Y'||ch =='y');
}
void display() {
    temp = head;
    if(head == NULL) {
        printf("List is empty\n");
    }
    else {
        while(temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->link;
        }

    }
}
void insertFront() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d",&newnode->data);
    if(head == NULL) {
        head = newnode = temp;
    }
    else {
        newnode->link = head;
        head = newnode;
    }
}
void insertEnd() {
    temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be appended:\t");
    scanf("%d", &newnode->data);
     if(head == NULL) {
        head = newnode = temp;
    }
    else {
    while(temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
    newnode->link = NULL;
}
}
void deletionEnd() {
    temp = head;
    if(head == NULL) {
        printf("List empty");
    }
    else {
        while(temp->link !=NULL) {
            prev = temp;
            temp = temp->link;
        }
        if(head == temp) {
            head = NULL;
            free(temp);
        }
        else{
        prev->link = NULL;
        free(temp);
        }
    }

}
void main() {
    printf("Creation\n");
    creation();
    display();
    printf("\nMenu\n1.Insert front\n2.Insert End\n");
    int ch;
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch) {
        case 1:insertFront();
        display();
        break;
        case 2:insertEnd();
        display();
        break;
        case 3: deletionEnd();
        display();
        break;
    }
}