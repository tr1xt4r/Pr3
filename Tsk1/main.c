#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int size;
    int capacity;
} ArrayList;

ArrayList* initializeArrayList(int initialSize) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->size = 0;
    list->capacity = initialSize;
    list->array = (int*)malloc(sizeof(int) * initialSize);
    return list;
}

void add(ArrayList* list, int item) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity);
    }
    list->array[list->size] = item;
    list->size++;
}

void insert(ArrayList* list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Invalid index for insertion\n");
        return;
    }

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity);
    }

    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }

    list->array[index] = item;
    list->size++;
}

int size(ArrayList* list) {
    return list->size;
}

void removeElement(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for removal\n");
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }

    list->size--;
}

void set(ArrayList* list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for modification\n");
        return;
    }

    list->array[index] = item;
}

int get(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for value retrieval\n");
        return -1;
    }

    return list->array[index];
}

void printArrayList(ArrayList* list) {
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

int main() {
    ArrayList* list = initializeArrayList(10);
    int choice;
    int item, index;

    do {
        printf("\nMenu:\n");
        printf("1. Add an element to the end of the list\n");
        printf("2. Insert an element in the middle of the list\n");
        printf("3. Number of elements in the list\n");
        printf("4. Remove an element by index\n");
        printf("5. Modify an existing element\n");
        printf("6. Get a value by index\n");
        printf("0. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &item);
                add(list, item);
                break;
            case 2:
                printf("Enter the index for insertion: ");
                scanf("%d", &index);
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(list, index, item);
                break;
            case 3:
                printf("Number of elements in the list: %d\n", size(list));
                break;
            case 4:
                printf("Enter the index to remove: ");
                scanf("%d", &index);
                removeElement(list, index);
                break;
            case 5:
                printf("Enter the index to modify: ");
                scanf("%d", &index);
                printf("Enter the new value: ");
                scanf("%d", &item);
                set(list, index, item);
                break;
            case 6:
                printf("Enter the index to retrieve a value: ");
                scanf("%d", &index);
                printf("Value at index %d: %d\n", index, get(list, index));
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }

        printArrayList(list);

    } while (choice != 0);

    free(list->array);
    free(list);

    return 0;
}
