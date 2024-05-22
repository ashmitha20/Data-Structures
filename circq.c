#include <stdio.h>
int front = -1;
int rear = -1;
int q[50];
int size;

void insertion(int item ) {
    if(rear >= size - 1) {
        printf("Queue overflow");
    }
    else {
        if(front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            q[rear] = item;
        }
        else {
            rear++;
            q[rear] = item;
        }
    }
}
void dequeue() {
    if(front == -1 && rear == -1) {
        printf("\n Queue Underflow\n");
    }
    else {
        int item = q[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
}
}