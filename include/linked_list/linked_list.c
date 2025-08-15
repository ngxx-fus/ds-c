#include "linked_list.h"



/// @brief 
// linked_list_t* ll_ptr;

#ifndef rep
#ifdef EXISTED_MARCO_WARNING
#pragma message("<rep> was defined, becareful! The defined thing may not work as expected!")
#endif
#define rep(type, i, __start, __end) for(type i = (__start); i < (__end); ++i)
#endif

#ifndef rev
#ifdef EXISTED_MARCO_WARNING
#pragma message("<rev> was defined, becareful! The defined thing may not work as expected!")
#endif
#define rev(type, i, __start, __end) for(type i = (__start); (i) > (__end); --i)
#endif

#if !defined(ll_root) || !defined(ll_head)
#ifdef EXISTED_MARCO_WARNING
#pragma message("<ll_root | ll_head> was defined, becareful! The defined thing may not work as expected!")
#endif
#define ll_head(linked_list_p) ((linked_list_p)->root_node)
#define ll_root(linked_list_p) ((linked_list_p)->root_node)
#endif

#ifndef ll_tail
#ifdef EXISTED_MARCO_WARNING
#pragma message("<ll_tail> was defined, becareful! The defined thing may not work as expected!")
#endif
#define ll_tail(linked_list_p) ((linked_list_p)->last_node_ptr)
#endif

#ifndef ll_size
#ifdef EXISTED_MARCO_WARNING
#pragma message("<ll_size> was defined, becareful! The defined thing may not work as expected!")
#endif
#define ll_size(linked_list_p) ((linked_list_p)->size)
#endif

#ifndef nd_next_ptr
#ifdef EXISTED_MARCO_WARNING
#pragma message("<nd_next_ptr> was defined, becareful! The defined thing may not work as expected!")
#endif
#define nd_next_ptr(node) ((node)->next_node_ptr) 
#endif 

#ifndef nd_prev_ptr
#ifdef EXISTED_MARCO_WARNING
#pragma message("<nd_prev_ptr> was defined, becareful! The defined thing may not work as expected!")
#endif
#define nd_prev_ptr(node) ((node)->prev_node_ptr)
#endif 

#ifndef nd_data
#ifdef EXISTED_MARCO_WARNING
#pragma message("<nd_data> was defined, becareful! The defined thing may not work as expected!")
#endif
#define nd_data(node) ((node)->data)
#endif 

#ifndef nd_index
#ifdef EXISTED_MARCO_WARNING
#pragma message("<nd_index> was defined, becareful! The defined thing may not work as expected!")
#endif
#define nd_index(node) ((node)->index)
#endif 

#ifndef __IS_NULL
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__IS_NULL> was defined, becareful! The defined thing may not work as expected!")
#endif
#define __IS_NULL(__PTR) (__PTR == NULL)
#endif 

#ifndef __IS_NOT_NULL
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__IS_NOT_NULL> was defined, becareful! The defined thing may not work as expected!")
#endif
#define __IS_NOT_NULL(__PTR) (__PTR != NULL)
#endif 

ll_node_t*      ll_set_prev_node_addr(  linked_list_t* ll_ptr,
                                        ll_node_t* specified_node, 
                                        ll_node_t* prev_node_ptr){
    WRITE_LOG("[LL-LOG] ll_set_prev_node_addr");
    nd_prev_ptr(specified_node) = prev_node_ptr;
    return specified_node;
}

ll_node_t*      ll_set_next_node_addr(  linked_list_t* ll_ptr,
                                        ll_node_t* specified_node,
                                        ll_node_t* next_node_ptr){
    WRITE_LOG("[LL-LOG] ll_set_next_node_addr");
    nd_next_ptr(specified_node) = next_node_ptr;
    return specified_node;
}

ll_node_t*      ll_set_data_node(       linked_list_t* ll_ptr,
                                        ll_node_t* specified_node, 
                                        ll_data_t data){
    WRITE_LOG("[LL-LOG] ll_set_data_node");
    nd_data(specified_node) = data;
    return specified_node;
}

ll_node_t*      ll_set_index_node(      linked_list_t* ll_ptr,
                                        ll_node_t* specified_node,
                                        ll_size_t index){
    WRITE_LOG("[LL-LOG] ll_set_index_node");
    nd_index(specified_node) = index;
    return specified_node;
}

ll_node_t*      ll_set_node(            linked_list_t* ll_ptr,
                                        ll_node_t* specified_node, 
                                        ll_node_t* prev_node, 
                                        ll_node_t* next_node, 
                                        ll_size_t index, 
                                        ll_data_t data){
    WRITE_LOG("[LL-LOG] ll_set_node(%p, %p, %p, %d, %d)", specified_node, 
                                                prev_node, next_node, index, data);
    nd_prev_ptr(specified_node) = prev_node;
    nd_next_ptr(specified_node) = next_node;
    nd_data(specified_node) = data;
    nd_index(specified_node) = index;
    return specified_node;
}

ll_node_t*      ll_node_create(         linked_list_t* ll_ptr,
                                        ll_node_t* prev_node,
                                        ll_node_t* next_node,
                                        ll_size_t index,
                                        ll_data_t data){
    WRITE_LOG("[LL-LOG] ll_node_create(%p, %p, %d, %d)", prev_node, 
                                                next_node, index, data);
    return ll_set_node(
        ll_ptr,
        (ll_node_t*) malloc(sizeof(ll_node_t)),
        prev_node,
        next_node,
        index,
        data
    );
}

ll_node_t*      ll_push_back(           linked_list_t* ll_ptr, 
                                        ll_data_t data){
    WRITE_LOG("[LL-LOG] ll_push_back(%u)", data);
    /// Create new node, then assign address_of(new_node) to tail->next_node_ptr
    nd_next_ptr(ll_tail(ll_ptr))=ll_node_create(
        ll_ptr,
        ll_tail(ll_ptr), 
        NULL, 
        nd_index(ll_tail(ll_ptr))+1, 
        data);
    /// Assign address_of(tail) to new_node->prev_node_ptr
    ll_tail(ll_ptr) = nd_next_ptr(ll_tail(ll_ptr));
    /// Update size of ll
    ll_size(ll_ptr) = ll_size(ll_ptr)+1;
    return ll_tail(ll_ptr);
}

linked_list_t*  ll_init(                ll_size_t ll_size_init){
    WRITE_LOG("[LL-LOG] ll_init(%d)", ll_size_init);
    /// Size error
    if (ll_size_init < 1) 
        return NULL;
    linked_list_t* ll_ptr =  (linked_list_t*) malloc(sizeof(linked_list_t));
    ll_ptr->size = ll_size_init;
    /// Failed to allocate
    if(!ll_ptr) return NULL;  
    ll_tail(ll_ptr) = ll_head(ll_ptr) = ll_node_create(
        ll_ptr,
        NULL, 
        NULL, 
        __LL_DEF_IVAL, 
        __LL_DEF_DVAL
    );
    rep(ll_size_t, i, 1, ll_ptr->size){
        // WRITE_LOG("[LL-LOG] Create node [%d], then assign address_of(new_node) to tail->next_node_ptr", nd_index(ll_tail(ll_ptr))+1);
        nd_next_ptr(ll_tail(ll_ptr))=ll_node_create(
            ll_ptr,
            ll_tail(ll_ptr), 
            NULL, 
            nd_index(ll_tail(ll_ptr))+1, 
            __LL_DEF_DVAL);
        // WRITE_LOG("[LL-LOG] Assign address_of(tail) to new_node->prev_node_ptr");
        ll_tail(ll_ptr) = nd_next_ptr(ll_tail(ll_ptr));
    }
    return ll_ptr;
}

ll_ret_code_t   ll_node_delete(         linked_list_t* ll_ptr, ll_node_t* specified_node){
    WRITE_LOG("[LL-LOG] ll_node_delete(%p)", specified_node);
    if(__IS_NULL(ll_ptr))
        return -1;
    else 
        free(specified_node);
    return 0;
}

ll_ret_code_t   ll_pop_back(            linked_list_t* ll_ptr){
    WRITE_LOG("[LL-LOG] ll_pop_back()");
    if(__IS_NULL(ll_ptr) || __IS_NULL(ll_tail(ll_ptr))) return -1;
    /// Get deleting address (tail address)
    ll_node_t* to_be_deleted = ll_tail(ll_ptr);
    WRITE_LOG("[LL-LOG] ll_pop_back() | To be del: %p", to_be_deleted);
    if(__IS_NOT_NULL(nd_prev_ptr(to_be_deleted))){
        /// Update tail address
        ll_tail(ll_ptr) = nd_prev_ptr(to_be_deleted);
        /// Update next_prt of tail
        nd_next_ptr(ll_tail(ll_ptr)) = NULL;
    }else{
        ll_head(ll_ptr) = ll_tail(ll_ptr) = NULL;
        WRITE_LOG("[LL-LOG] ll_pop_back() | %p is ROOT/HEAD node!", to_be_deleted);
    }
    /// Update size
    ll_size(ll_ptr) = ll_size(ll_ptr)-1;
    /// Delete 
    free(to_be_deleted);
    WRITE_LOG("[LL-LOG] ll_pop_back() | ll_size=%u", ll_size(ll_ptr));
    return 0;
}

ll_ret_code_t   ll_destroy(             linked_list_t* ll_ptr){
    WRITE_LOG("[LL-LOG] ll_destroy()");
    if(__IS_NULL(ll_ptr)) return -1;
    ll_ret_code_t ret;
    while(1){
        ret = ll_pop_back(ll_ptr);
        if(ret != (ll_ret_code_t)(-1)){
            continue;
        }else{
            if(ll_size(ll_ptr) > 0){ 
                WRITE_LOG("[LL-LOG] ll_destroy() | ll_size=%d", ll_size(ll_ptr));
                WRITE_LOG("[LL-LOG] ll_destroy() | Error");
                return -1;
            } else{
                WRITE_LOG("[LL-LOG] ll_destroy() | Deleted all nodes");
                break;
            }
        }
    }
    free(ll_ptr);
    return 0;
}

ll_node_t*      ll_node_at(             linked_list_t* ll_ptr, ll_size_t index){
    WRITE_LOG("[LL-LOG] ll_node_at(%d)", index);
    /// Search from root
    ll_node_t* temp_node = ll_root(ll_ptr);
    while( temp_node ){
        if (nd_index(temp_node) == index){
            return temp_node;
        }
        temp_node = nd_next_ptr(temp_node);
    }
    return NULL;
}

ll_data_t       ll_data_at(              linked_list_t* ll_ptr, ll_size_t index){
    WRITE_LOG("[LL-LOG] ll_data_at(%d, index)");
    /// Search from root
    ll_node_t* temp_node = ll_root(ll_ptr);
    while( temp_node ){
        if (nd_index(temp_node) == index){
            return nd_data(temp_node);
        }
        temp_node = nd_next_ptr(temp_node);
    }
    return -1;
}

ll_size_t       ll_index_at(            linked_list_t* ll_ptr, ll_node_t* specifed_node){
    WRITE_LOG("[LL-LOG] ll_index_at(%p)", specifed_node);
    /// Search from root
    ll_node_t* temp_node = ll_root(ll_ptr);
    while( temp_node ){
        if (temp_node-specifed_node == 0){
            return nd_index(temp_node);
        }
        temp_node = nd_next_ptr(temp_node);
    }
    return -1;
}

ll_ret_code_t   ll_delete_node(         linked_list_t* ll_ptr, ll_node_t* specified_node){
    WRITE_LOG("[LL-LOG] ll_delete_node(%p)", specified_node);
    if(__IS_NULL(specified_node)) return -1;
    /// Delete root/head
    if(ll_head(ll_ptr) == specified_node){
        ll_head(ll_ptr) = nd_next_ptr(specified_node);
        nd_prev_ptr(ll_head(ll_ptr)) = NULL;
        #ifdef AUTO_UPDATE_NODE_INDEX
            ll_node_t* tmp_node = nd_next_ptr(ll_head(ll_ptr));
            while(__IS_NOT_NULL(tmp_node)){
                nd_index(tmp_node) = nd_index(nd_prev_ptr(tmp_node));
                tmp_node = nd_next_ptr(tmp_node);
            }
        #endif
    }else 
    /// Delete tail
    if(ll_tail(ll_ptr) == specified_node){
        return ll_pop_back(ll_ptr);
    }
    /// Delete midle node
    else{
        #ifdef AUTO_UPDATE_NODE_INDEX
        ll_node_t* tmp_node = ll_tail(ll_ptr);
        while(tmp_node!=specified_node){
            // WRITE_LOG("[LL-LOG] ll_delete_node() | Update node: %p", tmp_node);
            nd_index(tmp_node) = nd_index(nd_prev_ptr(tmp_node));
            tmp_node = nd_prev_ptr(tmp_node);
        }
        #endif
        nd_next_ptr(nd_prev_ptr(specified_node)) = nd_next_ptr(specified_node);
        WRITE_LOG("[LL-LOG] ll_delete_node() | set-pointer: %p-->%p", 
                    nd_prev_ptr(specified_node),
                    nd_next_ptr(nd_prev_ptr(specified_node)));
        nd_prev_ptr(nd_next_ptr(specified_node)) = nd_prev_ptr(specified_node);
        WRITE_LOG("[LL-LOG] ll_delete_node() | set-pointer: %p<--%p", 
            nd_prev_ptr(nd_next_ptr(specified_node)),
                    nd_next_ptr(specified_node));
    }
    WRITE_LOG("[LL-LOG] ll_delete_node() | Update ll-size");
    ll_size(ll_ptr) = ll_size(ll_ptr) - 1;
    free(specified_node);
    return 0;
}

ll_ret_code_t   ll_delete_node_index(   linked_list_t* ll_ptr, ll_size_t index){
    WRITE_LOG("[LL-LOG] ll_delete_node_index(%d)", index);
    ll_node_t* temp_node = ll_root(ll_ptr);
    while( temp_node ){
        if (nd_index(temp_node) == index){
            ll_delete_node(ll_ptr, temp_node);
            return 0;
        }else{
            temp_node = nd_next_ptr(temp_node);
        }
    }
    return -1;
}

#if defined(LOG) && defined(WRITE_LOG)
void            log_all_nodes(linked_list_t* ll_ptr){
    WRITE_LOG("[LL-LOG] log_all_nodes()");
    ll_node_t* tmp_node = ll_head(ll_ptr);
    while(__IS_NOT_NULL(tmp_node)){
        WRITE_LOG("[LL-LOG] log_all_nodes() | %p<--%p[%d|%d]-->%p", 
                    nd_prev_ptr(tmp_node), tmp_node, nd_index(tmp_node), 
                    nd_data(tmp_node), nd_next_ptr(tmp_node));
        tmp_node = nd_next_ptr(tmp_node);
    }
}

#endif