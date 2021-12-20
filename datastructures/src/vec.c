#include "vec.h"

LinkedList* linked_list() {
    LinkedList* ret = (LinkedList*) malloc(sizeof(LinkedList));
    ret->length = 0;
    ret->head = NULL;
}

/// Deallocs the list, all nodes contained, and data contained as well
/// Usage:
/// ll_destroy(my_list);
/// Returns 
void ll_destroy(LinkedList* list) {
    while (list->head != NULL) {
        // free(cur->data); //TODO: This line may cause problematic double frees on the same data.
        Node* next = list->head->next;
        free(list->head);
        list->head = next;
    }
    free(list);
}

/// Append takes malloc'd data and dynamically allocates space on the heap
/// for the new node. This is necessary because we cannot know for sure if
/// the library user will malloc and free properly.
/// Usage example:
/// append(my_list, data_to_add);
/// Implementation details:
void ll_append(LinkedList* list, void* data_to_add) {
    //TODO: Add tail field in LinkedList struct for O(1) insertion
    if (list == NULL || data_to_add == NULL) {
        fprintf(stderr, "append list pointer null");
    }
    
    Node* cur = list->head;
    // No elements yet in list
    if (cur == NULL) {
        list->head = (Node*) malloc(sizeof(Node));
        list->head->data = data_to_add;
        list->head->next = NULL;
        list->length++;
    } else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = (Node*) malloc(sizeof(Node));
        cur->next->data = data_to_add;
        cur->next->next = NULL;
        list->length++;
    }
}

int ll_is_empty(LinkedList* list) {
    if (list == NULL) {
        fprintf(stderr, "list pointer null");
    }
    return (list->length == 0);
}

