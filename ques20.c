#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// a) Insertion at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// b) Insertion at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// c) Insertion after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// d) Deletion of a node by value
void deleteByValue(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL) return;

    // Unlink and free node
    prev->next = temp->next;
    free(temp);
}

// e) Deletion of a node by position (0-based index)
void deleteByPosition(struct Node** head, int position) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    // If head needs to be removed
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find previous node
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is out of range
    if (temp == NULL || temp->next == NULL) return;

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// f) Traversal and printing
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function for demonstration
int main() {
    struct Node* head = NULL;

    // Insertions
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);
    insertAfter(head->next, 15); // Insert after 10

    printf("Linked List after insertions: ");
    printList(head);

    // Deletion by value
    deleteByValue(&head, 15);
    printf("After deleting 15: ");
    printList(head);

    // Deletion by position
    deleteByPosition(&head, 1);
    printf("After deleting node at position 1: ");
    printList(head);

    return 0;
}
