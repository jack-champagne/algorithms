#ifndef VEC
#define VEC

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int length;
} LinkedList;

LinkedList* linked_list();
void ll_append(LinkedList* list, void* data_to_add);
int ll_is_empty(LinkedList* list);
void ll_destroy(LinkedList* list);

#endif

