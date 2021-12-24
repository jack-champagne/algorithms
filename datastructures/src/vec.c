#include "vec.h"

/// Mallocs a new linked list struct and initializes fields.
/// Usage:
/// LinkedList* my_list = linked_list();
/// 
/// Returns pointer to dynamically allocated linked list
LinkedList* linked_list() {
    LinkedList* ret = (LinkedList*) malloc(sizeof(LinkedList));
    ret->length = 0;
    ret->head = NULL;
    ret->tail = NULL;

    return ret;
}

/// Deallocs the list, all nodes contained, and data contained as well
/// Usage:
/// ll_destroy(my_list);
///
/// Returns void
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
/// append(my_list, data_to_append);
/// 
/// Returns void
void ll_append(LinkedList* list, void* data_to_append) {
    ll_insert_at(list, list->length, data_to_append);
}

/// Inserts node after the node given and manages pointers properly. Assume node
/// to insert is a new node that is not currently in the list.
/// Special case: if prev is NULL, insert node at head.
/// Usage:
/// ll_insert_after(my_list, predecessor_node, new_node);
///
/// Returns void
void ll_insert_at(LinkedList* list, int index, void* data_to_insert) {
    if (list == NULL || data_to_insert == NULL) {
        fprintf(stderr, "list or data_to_insert NULL, cannot insert after");
        return;
    }

    // Design choice: Originally, this implementation for insert_after did not
    // include a LinkedList* list parameter because insertion of a node only requires
    // the proper swapping of references. This was changed to allow the list->length
    // parameter to remain updated.
    Node* new_node = ll_node(data_to_insert);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        list->length = 1;
        return;
    }

    Node* prev = get_node(list, index - 1);
    Node* successor = get_node(list, index);
    if (prev == NULL) {
        successor = list->head;
        list->head = new_node;

    } else {
        if (prev == list->tail) {
            list->tail = new_node;
        }
        successor = prev->next;
        prev->next = new_node;
    }

    new_node->next = successor;
    list->length++;
}

/// Prepend data to beginning of list (the head)
/// Usage:
/// ll_prepend(my_list, data_to_prepend)
void ll_prepend(LinkedList* list, void* data_to_prepend) {
    ll_insert_at(list, 0, data_to_prepend);
}

/// Returns the data at specified index in linked list
/// Usage:
/// printf("%d", *(int*)ll_get(my_list, 1)); // Prints second element in my_list if it exists.
/// Runtime: O(n)
void* ll_get(LinkedList* list, int index) {
    if (list == NULL || index < 0 || index >= list->length) {
        fprintf(stderr, "list null or index out of bounds");
        return NULL;
    }

    return get_node(list, index)->data;
}

/// Removes node at specified index
/// Usage:
/// int* data = ll_remove(my_list, 1); // Removes and returns pointer to data of the second element of list if element exists
/// Runtime: O(n) (when we traverse), O(1) when removing head
void* ll_remove(LinkedList* list, int index) {
    if (list == NULL || index < 0 || index >= list->length) {
        fprintf(stderr, "list null or index out of bounds");
        return NULL;
    }

    Node* removed_node;
    Node* prev = get_node(list, index - 1);
    if (index == 0) {
        // Change head
        removed_node = list->head;
        list->head = removed_node->next;
    } else {
        // Repair list
        removed_node = get_node(list, index);
        prev->next = removed_node->next;
    }

    // Fix tail pointer if needed
    if (removed_node == list->tail) {
        list->tail = prev;
    }
    list->length--;

    void* ret = removed_node->data;
    free(removed_node);
    return ret;
}

/// Get node at index. Not for outside use. For library use only.
/// Usage:
/// Node* node_at_index = ll_get(my_list, 1); // Returns the second node in the list if it exists
/// Returns Node* to node struct rep. index i.
Node* get_node(LinkedList* list, int index) {
    if (index >= list->length || index < 0) {
        return NULL;
    }

    Node* ret = list->head;
    int i = 0;
    while (ret != NULL && i < index) {
        ret = ret->next;
        i++;
    }

    return ret;
}

/// Check to see if list is empty
/// Usage:
/// if (ll_is_empty(my_list)) { foo(); }
///
/// Returns 1 if empty, 0 if not empty.
int ll_is_empty(LinkedList* list) {
    if (list == NULL) {
        fprintf(stderr, "list pointer null");
    }
    return (list->length == 0);
}

Node* ll_node(void* new_data) {
    Node* ret = (Node*) malloc(sizeof(Node));
    ret->data = new_data;
    ret->next = NULL;
    return ret;
}