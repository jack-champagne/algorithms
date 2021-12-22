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
    Node* tail; 
} LinkedList;

LinkedList* linked_list();
void ll_append(LinkedList* list, void* data_to_add);
int ll_is_empty(LinkedList* list);
void ll_destroy(LinkedList* list);
void ll_insert_after(LinkedList* list, Node* prev, void* data_to_insert);
void ll_prepend(LinkedList* list, void* data_to_prepend);
void* ll_get(LinkedList* list, int index);
void* ll_remove(LinkedList* list, int index);
Node* get_node(LinkedList* list, int index);
Node* ll_node(void* new_data);

#endif

