#include<stdio.h>
#include<stdlib.h>

struct node {
    int coef;
    int expo;
    struct node *link;
};
struct node *head1=NULL,*head2=NULL,*head3=NULL;
struct node *creation() {
    char ch;
    struct node *temp = NULL;
    struct node *head = NULL;
    do {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d",&newnode->coef);
        printf("Enter the exponent :");
        scanf("%d",&newnode->expo);
        newnode->link = NULL;
        if(head == NULL) {
            head = temp = newnode;
            } else {
                temp->link = newnode;
                temp = newnode;
        }
        printf("\nDo you want to continue? Y/N\n");
        scanf(" %c",&ch);
    }while(ch == 'Y'||ch == 'y');
    return head;
}
void display(struct node *head) {
    if(head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    int coeffs[50],expos[50];
    int count = 0;
    while(head != NULL) {
        coeffs[count] = head->coef;
        expos[count] = head->expo;
        count++;
        head = head->link;
    }
    for(int i =0; i < count - 1;i++) {
        for(int j = i+1; j < count;j++) {
            if(expos[i] < expos[j]) {
                int temp = expos[i];
                expos[i] = expos[j];
                expos[j] = temp;

                temp = coeffs[i];
                coeffs[i] = coeffs[j];
                coeffs[j] = temp;
            }
        }
    }
    for(int i = 0; i < count; i++) {
        printf("%dx^%d",coeffs[i],expos[i]);
        if(i != count - 1) {
            printf(" + ");
        }
    }
        printf("\n");
    }
    void add() {
        struct node *temp1 = head1, *temp2 = head2, *temp3 = head3 = NULL;
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->expo == temp2->expo) {
                if(temp3 == NULL) {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    head3 = newnode;
                    temp3 = newnode;
                }
                else {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    temp3->link = newnode;
                    temp3 = newnode;
                }
                temp3->coef = temp1->coef + temp2->coef;
                temp3->expo = temp1->expo;
                temp3->link = NULL;
                temp1 = temp1->link;
                temp2 = temp2->link;
            }
            else if(temp1->expo > temp2->expo) {
                  if(temp3 == NULL) {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    head3 = newnode;
                    temp3 = newnode;
                }
                else {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    temp3->link = newnode;
                    temp3 = newnode;
                }
                temp3->coef = temp1->coef;
                temp3->expo = temp1->expo;
                temp3->link = NULL;
                temp1 = temp1->link;
            }
            else {
                if(temp3 == NULL) {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    head3 = newnode;
                    temp3 = newnode;
                }
                else {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    temp3->link = newnode;
                    temp3 = newnode;
                }
                temp3->coef = temp2->coef;
                temp3->expo = temp2->expo;
                temp3->link = NULL;
                temp2 = temp2->link;
            }
        }
        while(temp1 != NULL) {
             if(temp3 == NULL) {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    head3 = newnode;
                    temp3 = newnode;
                }
                else {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    temp3->link = newnode;
                    temp3 = newnode;
                }
                temp3->coef = temp1->coef;
                temp3->expo = temp1->expo;
                temp3->link = NULL;
                temp1 = temp1->link;
            }
        while(temp2 != NULL) {
             if(temp3 == NULL) {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    head3 = newnode;
                    temp3 = newnode;
                }
                else {
                    struct node *newnode = (struct node*)malloc(sizeof(struct node));
                    temp3->link = newnode;
                    temp3 = newnode;
                }
                temp3->coef = temp2->coef;
                temp3->expo = temp2->expo;
                temp3->link = NULL;
                temp2 = temp2->link;
            }
    }
    void addLikeTerms() {
    struct node *temp3 = head3;

    while (temp3 != NULL) {
        struct node *prev = temp3;
        struct node *next = temp3->link;

        while (next != NULL) {
            if (temp3->expo == next->expo) {
                temp3->coef += next->coef;
                prev->link = next->link;
                free(next);
                next = prev->link;
            } else {
                prev = next;
                next = next->link;
            }
        }
        temp3 = temp3->link;
    }
}

    void main() {
        printf("Enter coefficient of poly 1: ");
        head1 = creation();
        printf("\nEnter the terms of the second polynomial:\n");
        head2 = creation();
        printf("\nFirst polynomial: ");
    display(head1);
    printf("Second polynomial: ");
    display(head2);
    add();
    addLikeTerms();
    display(head3);

    }


