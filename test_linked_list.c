#include "stdio.h"

#include "linked_list/linked_list.h"

int main(void){
    printf("----- Test LINKED-LIST program -----\n");
    linked_list_t*    ll_ptr = ll_init(10);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_delete_node_index(ll_ptr, 6);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_delete_node_index(ll_ptr, 9);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_pop_back(ll_ptr);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_push_back(ll_ptr, 172);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_delete_node_index(ll_ptr, 0);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_push_back(ll_ptr, 17);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_delete_node_index(ll_ptr, 15);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes(ll_ptr);
    #endif
    ll_destroy(ll_ptr);
}