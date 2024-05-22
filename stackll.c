#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*link;
};
struct node*top = NULL;
struct node*temp, *newnode;
void push() {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the element of the stack: ");
        scanf("%d",&newnode->data);
        newnode->link = NULL;
        if(top == NULL) {
            top = newnode;
            temp = newnode;
        }
        else {
                newnode->link = top;
                top = newnode;
         }
}
        
void pop() {
    temp = top;
    if(top == NULL) {
        printf("Stack empty");
        return;
    }
    else {
        top = temp->link;
        free(temp);
    }
}


void display() {
    if(top == NULL) {
        printf("\nStack is empty");
    }
    else{
        temp = top;
        while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->link;
        }
  }
}
void main() {
    int ch;
    while(1) {
        printf("Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: push();
            display();
            break;
            case 2: pop();
            display();
            break;
            case 3:display();
            break;
            case 4:printf("Exit");
            exit(0);
            default: printf("Invalid");
        }
    }
}
