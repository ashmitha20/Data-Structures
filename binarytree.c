#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *creation() {
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of new node: ");
    scanf("%d",&x);
    if(x == -1) {
        return 0;
    }
    else {
        newnode->data = x;
        printf("\nEnter the left child of %d : ",x);
        newnode->left = creation();
        printf("Enter the right child of %d : ",x);
        newnode->right = creation();
        return newnode;
    }
}
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}
void main() {
    struct node *root = creation();
    printf("Inorder: ");
    inorder(root);
}