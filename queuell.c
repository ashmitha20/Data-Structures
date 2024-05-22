#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*link;
};
struct node*front = NULL;
struct node*rear = NULL;
struct node*temp, *newnode;
void enqueue() {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element of the queue: ");
        scanf("%d",&newnode->data);
        newnode->link = NULL;
        if(front == NULL) {
            front= rear = newnode;
        }
        else {
               while(rear->link != NULL) {
                rear = rear->link;
               }
               rear->link = newnode;
            }
}
void deq() {
    temp = front;
    if(front == NULL) {
        printf("Queue empty");
    }
    else if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = temp->link;
        free(temp);
    }
}
        

void display() {
    if(front == NULL) {
        printf("\nQueue is empty");
    }
    else{
        temp = front;
        while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->link;
        }
  }
}
void main() {
    int ch;
    while(1) {
    printf("\n1.Enqueue\n2.Dequeue\n3.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch) {
        case 1:enqueue();
        display();
        break;
        case 2:deq();
        display();
        break;
        case 3:printf("Exit");
        exit(0);
        default: printf("Invalid choice\n");
    }
    }
}



