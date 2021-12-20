#include "vec.h"

int main() {
    LinkedList* new_llist = linked_list();
    int* dyn_int = (int*) malloc(sizeof(int));
    *dyn_int = 255;
    
    int* dyn_int2 = (int*) malloc(sizeof(int));
    *dyn_int2 = 871;

    ll_append(new_llist, dyn_int);
    ll_append(new_llist, dyn_int2);
    ll_append(new_llist, dyn_int2);
    printf("%d: %d, %d, %d\n", ll_is_empty(new_llist), *(int*)(new_llist->head->data), *(int*)(new_llist->head->next->data), *(int*)(new_llist->head->next->next->data));
    *dyn_int2 = 65;
    printf("%d: %d, %d, %d\n", ll_is_empty(new_llist), *(int*)(new_llist->head->data), *(int*)(new_llist->head->next->data), *(int*)(new_llist->head->next->next->data));
    free(dyn_int);
    free(dyn_int2);
    ll_destroy(new_llist);
}