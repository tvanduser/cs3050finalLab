#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
I am going to use a linked list for this to make inserting and deleting easier even though it may make some things slower
*/

// ----- ADTS -----
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List{
    Node *head;
    Node *tail;
    int size;
} List;

// ----- HELPER FUNCTIONS -----
Node *createNode(int data){
    Node *n;
    n = malloc(sizeof(Node));
    if(!n){
        return NULL; //creation failed
    }
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    return n;
}


List *createNewList(){
    List *l;
    l = malloc(sizeof(List));
    if(!l){
        return NULL; //list creation failed
    }
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

void insertAtHead(List *l, int data) {
    Node *n = createNode(data);
    n->next = l->head;
    if (l->head != NULL) {
        l->head->prev = n;
    }
    l->head = n;
    if (l->tail == NULL) {
        l->tail = n;
    }

    l->size++;
}

// ----- REQUIRED FUNCTIONS -----
void insertAtEnd(List *l, int data) {
    Node *n = createNode(data);
    if (l->tail == NULL) { // empty list
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        n->prev = l->tail;
        l->tail = n;
    }
    l->size++;
}

Node* removeIntFromList(List *l, int rmvInt) {
    Node *cur = l->head;

    while (cur != NULL) {
        if (cur->data == rmvInt) {
            if (cur->prev)
                cur->prev->next = cur->next;
            else
                l->head = cur->next;

            if (cur->next)
                cur->next->prev = cur->prev;
            else
                l->tail = cur->prev;

            free(cur);
            l->size--;
            break;
        }
        cur = cur->next;
    }
    
    return l->head;
}

int getIntAtIndex(List *l, int index) {
    if (index < 0 || index >= l->size) {
        printf("Index out of range, could not find value at that index...\n");
        return -1;
    }

    int pos = 0;
    Node *tmp = l->head;
    while (tmp != NULL) {
        if (pos == index) {
            return tmp->data;
        }
        tmp = tmp->next;
        pos++;
    }

    // This point shouldn't be reached if bounds are checked
    return -1;
}

int getSizeOfList(List *l){
    return l->size;
}

bool checkListEmpty(List *l){
    return l->size == 0;
}

void printList(List *l) {
    Node *cur = l->head;
    printf("List (size %d): ", l->size);
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void clearList(List *l) {
    Node *cur = l->head;
    Node *next;

    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    // Reset list structure
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void sortListAscending(List *l) {
    if (l->head == NULL || l->head->next == NULL) {
        return; // list is empty or has one element
    }

    bool swapped;
    Node *cur;
    
    do {
        swapped = false;
        cur = l->head;

        while (cur->next != NULL) {
            if (cur->data > cur->next->data) {
                // Swap data values
                int temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;

                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}

void sortListDescending(List *l) {
    if (l->head == NULL || l->head->next == NULL) {
        return; // list is empty or has one element
    }

    bool swapped;
    Node *cur;

    do {
        swapped = false;
        cur = l->head;

        while (cur->next != NULL) {
            if (cur->data < cur->next->data) {
                // Swap data values
                int temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;

                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}

int findMaxInt(List *l){ //scan through linearly since its faster even though I could use the sorting
    if(l->head == NULL){
        printf("List is empty\n");
        return -1;
    }

    //setup
    int max = l->head->data;
    Node *cur = l->head->next;

    //logic
    while(cur != NULL){
        if(cur->data > max){
            max = cur->data;
        }
        cur = cur->next;
    }
    return max;
}


int main() {
    // Agument Data Structure
    // Problem 4: Implement a data structure that can store a list of integers
    // and supports the following operations:
    // 1. Insert an integer at the end of the list *done
    // 2. Remove an integer from the list *done
    // 3. Get the integer at a specific index in the list *done
    // 4. Get the size of the list *done
    // 5. Check if the list is empty *done
    // 6. Clear the list *done
    // 7. Print the list *done
    // 8. Sort the list in ascending order *done
    // 9. Sort the list in descending order *done
    // 10. Find the maximum integer in the list *done
    // TODO: Implement this problem's solution


    // ----- TESTING -----
    List *myList = createNewList();

    // Insert some values
    insertAtEnd(myList, 5);
    insertAtEnd(myList, 3);
    insertAtEnd(myList, 9);
    insertAtEnd(myList, 1);
    insertAtHead(myList, 7);
    printList(myList);

    // Get value at index
    printf("Value at index 2: %d\n", getIntAtIndex(myList, 2));

    // Check size
    printf("List size: %d\n", getSizeOfList(myList));

    // Remove an item
    printf("Removing value 3...\n");
    removeIntFromList(myList, 3);
    printList(myList);

    // Sort ascending
    printf("Sorting ascending...\n");
    sortListAscending(myList);
    printList(myList);

    // Sort descending
    printf("Sorting descending...\n");
    sortListDescending(myList);
    printList(myList);

    // Find max
    printf("Max value in list: %d\n", findMaxInt(myList));

    // Clear list
    printf("Clearing list...\n");
    clearList(myList);
    printList(myList);

    // Check if empty
    if (checkListEmpty(myList)) {
        printf("List is empty.\n");
    } else {
        printf("List is not empty.\n");
    }

    // Clean up the list struct itself
    free(myList);

    return 0;
}
