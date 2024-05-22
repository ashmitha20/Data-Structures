#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;
struct node* temp2 = NULL;
struct node* newNode = NULL;
int data;

void insertBeginning() {
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertEnd() {
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtPosition(int position) {
    if (position < 1) {
        printf("Invalid position. Please enter a position greater than or equal to 1.\n");
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1 || head == NULL) {
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            newNode->next = head;
            temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            head = newNode;
        }
    } else {
        temp = head;
        temp2 = head;
        int count = 1, counter = 1;

        while (temp->next != head && count < position - 1) {
            temp = temp->next;
            count++;
        }
        
        while (temp2->next != head) {
       		temp2 = temp2->next;
        	counter++;
        }
	
	printf("COUNT = %d\n", counter);
	if (position == counter+1) insertEnd();
	else if (position > counter+1) printf("Invalid position!");
	else {
		newNode->next = temp->next;
        	temp->next = newNode;
	}
    }
}

void deleteAtPosition(int position) {
    if (position < 1 || head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    if (position == 1) {
        temp = head;

        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    } else {
        temp = head;
        int count = 1;

        while (temp->next != head && count < position - 1) {
            temp = temp->next;
            count++;
        }
	
        if (temp->next == head) {
            printf("Invalid position. Please enter a valid position.\n");
            return;
        }

        struct node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void createList() {
    char choice;

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);

        insertEnd();

        printf("Do you want to create more nodes? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
    } else {
        temp = head;

        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
    } else {
        temp = head;

        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct node* prev = NULL;

            do {
                prev = temp;
                temp = temp->next;
            } while (temp->next != head);

            prev->next = head;
            free(temp);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;

        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("\n");
    }
}

int main() {
    int choice, position;

    printf("Creating a circular singly linked list...\n");
    createList();
    printf("Created Circular Singly Linked List is: \n");
    display();

    do {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete at Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertBeginning();
            display();
            break;
        case 3:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertEnd();
            display();
            break;
        case 4:
            printf("Enter position for insertion: ");
            scanf("%d", &position);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtPosition(position);
            display();
            break;
        case 5:
            deleteBeginning();
            display();
            break;
        case 6:
            deleteEnd();
            display();
            break;
        case 7:
            printf("Enter position for deletion: ");
            scanf("%d", &position);
            deleteAtPosition(position);
            display();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}