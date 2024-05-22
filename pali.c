#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Node definition for a singly linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertNode(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // An empty list or a list with one node is a palindrome
    }

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev_slow = head;
    struct Node* mid = NULL;
    bool isPalin = true;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL) { // For odd number of nodes, move slow pointer to the next node
        mid = slow;
        slow = slow->next;
    }

    prev_slow->next = NULL; // Split the list into two halves

    slow = reverseList(slow); // Reverse the second half of the list

    struct Node* temp1 = head;
    struct Node* temp2 = slow;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            isPalin = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    slow = reverseList(slow); // Restore the second half of the list
    if (mid != NULL) { // If the number of nodes was odd, reconnect the halves
        prev_slow->next = mid;
        mid->next = slow;
    } else {
        prev_slow->next = slow;
    }

    return isPalin;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    char input[100];

    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        insertNode(&head, input[i]);
    }

    printf("Linked List: ");
    displayList(head);

    if (isPalindrome(head)) {
        printf("The given string forms a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    freeList(head); // Free allocated memory
    return 0;
}
