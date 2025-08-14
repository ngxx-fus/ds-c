#include "stdio.h"

#include "DS/linked_list.h"

int main(void){
    printf("----- Test LINKED-LIST program -----\n");
    ll_init(10);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_delete_node_index(6);
    ll_delete_node_index(9);
    ll_pop_back();
    ll_push_back(172);
    ll_delete_node_index(0);
    ll_delete_node_index(11);
    #if defined(LOG) && defined(WRITE_LOG)
        log_all_nodes();
    #endif
    ll_destroy();
}