#include "vec.h"

int main() {
    // Code examples?
    LinkedList* new_llist = linked_list();
    int* dyn_int = (int*) malloc(sizeof(int));
    *dyn_int = 255;
    
    int* dyn_int2 = (int*) malloc(sizeof(int));
    *dyn_int2 = 871;

    int i = 552;

    ll_append(new_llist, dyn_int);
    ll_prepend(new_llist, dyn_int2);
    ll_append(new_llist, &i);
    printf("%d: %d, %d, %d\n", ll_is_empty(new_llist), *(int*)(new_llist->head->data), *(int*)(new_llist->head->next->data), *(int*)(new_llist->head->next->next->data));
    printf("%d\n", new_llist->length);
    printf("%d\n", *(int*)new_llist->tail->data);
    ll_prepend(new_llist, &i);
    printf("%d: %d, %d, %d, %d\n", ll_is_empty(new_llist), *(int*)(new_llist->head->data), *(int*)(new_llist->head->next->data), *(int*)(new_llist->head->next->next->data), *(int*)(new_llist->tail->data));
    printf("%d\n", *(int*)ll_get(new_llist, 0));
    ll_prepend(new_llist, dyn_int2);
    printf("%d: %d, %d, %d, %d, %d\n", ll_is_empty(new_llist), *(int*)(new_llist->head->data), *(int*)(new_llist->head->next->data), *(int*)(new_llist->head->next->next->data), *(int*)(new_llist->head->next->next->next->data), *(int*)(new_llist->tail->data));
    ll_remove(new_llist, 0);
    printf("%d: %d, %d, %d, %d\n", ll_is_empty(new_llist), *(int*)(new_llist->head->data), *(int*)(new_llist->head->next->data), *(int*)(new_llist->head->next->next->data), *(int*)(new_llist->head->next->next->next->data));
    printf("%d\n", *(int*)ll_get(new_llist, 0));
    printf("%d\n", *(int*)ll_get(new_llist, 3));
    free(dyn_int);
    free(dyn_int2);
    ll_destroy(new_llist);
}