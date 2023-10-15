#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(struct LinkedList* list, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

void insert(struct LinkedList* list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Invalid index for insertion\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;
}

int size(struct LinkedList* list) {
    return list->size;
}

void removeAt(struct LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for removal\n");
        return;
    }

    if (index == 0) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        struct Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    list->size--;
}

void set(struct LinkedList* list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for replacement\n");
        return;
    }

    struct Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = item;
}

int get(struct LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for retrieval\n");
        return -1; // Return -1 for an invalid index
    }

    struct Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList* myList = createLinkedList();
    int choice, item, index;

    do {
        printf("\nList of Operations:\n");
        printf("1. Add an element to the end of the list\n");
        printf("2. Insert an element into the middle of the list\n");
        printf("3. Get the size of the list\n");
        printf("4. Remove an element by index\n");
        printf("5. Replace an existing element\n");
        printf("6. Get the value by index\n");
        printf("0. Exit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &item);
                add(myList, item);
                break;
            case 2:
                printf("Enter the index for insertion: ");
                scanf("%d", &index);
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(myList, index, item);
                break;
            case 3:
                printf("Size of the list: %d\n", size(myList));
                break;
            case 4:
                printf("Enter the index for removal: ");
                scanf("%d", &index);
                removeAt(myList, index);
                break;
            case 5:
                printf("Enter the index for replacement: ");
                scanf("%d", &index);
                printf("Enter the new element: ");
                scanf("%d", &item);
                set(myList, index, item);
                break;
            case 6:
                printf("Enter the index to retrieve: ");
                scanf("%d", &index);
                printf("Value at index %d: %d\n", index, get(myList, index));
                break;
            case 0:
                break;
            default:
                printf("Unknown operation\n");
        }

        printf("Current state of the list:\n");
        display(myList);
    } while (choice != 0);

    return 0;
}
