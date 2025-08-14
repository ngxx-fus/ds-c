#include "stdio.h"

#include "DS/linked_list.h"

int main(void){
    printf("----- Test LINKED-LIST program -----\n");
    ll_init(10);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_delete_node_index(6);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_delete_node_index(9);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_pop_back();
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_push_back(172);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_delete_node_index(0);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_push_back(17);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_delete_node_index(15);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_destroy();
}