#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/// Uncomment to enable auto update index
/// If you uncomment the line below, meaning anable 
/// Auto update index after remove a node,
/// It may be cause increasing of running time
// #define AUTO_UPDATE_NODE_INDEX 

/// Un-comment two lines below enable LOG, and specify the actually log-function 
// #define LOG
// #define WRITE_LOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

/// Un-comment to enable defined macro warning
/// #define EXISTED_MARCO_WARNING

#ifndef LOG
#define WRITE_LOG(fmt, ...)
#endif

#ifndef __LL_DEF_DVAL
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__LL_DEF_DVAL> was defined, becareful! The defined thing may not work as expected!")
#endif
/// @brief Default data value
#define __LL_DEF_DVAL                   0
#endif

#ifndef __LL_DEF_IVAL
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__LL_DEF_IVAL> was defined, becareful! The defined thing may not work as expected!")
#endif
/// @brief Default index value
#define __LL_DEF_IVAL                   0
#endif

#ifndef __LL_DEFAULT_DATA_TYPE
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__LL_DEFAULT_DATA_TYPE> was defined, becareful! The defined thing may not work as expected!")
#endif
#define __LL_DEFAULT_DATA_TYPE          uint8_t 
#endif

#ifndef __LL_DEFAULT_SIZE_TYPE
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__LL_DEFAULT_SIZE_TYPE> was defined, becareful! The defined thing may not work as expected!")
#endif
#define __LL_DEFAULT_SIZE_TYPE          int32_t
#endif 

#ifndef __LL_DEFAULT_RETURN_CODE_TYPE
#ifdef EXISTED_MARCO_WARNING
#pragma message("<__LL_DEFAULT_RETURN_CODE_TYPE> was defined, becareful! The defined thing may not work as expected!")
#endif
#define __LL_DEFAULT_RETURN_CODE_TYPE   uint8_t
#endif

typedef __LL_DEFAULT_DATA_TYPE          ll_data_t;
typedef __LL_DEFAULT_SIZE_TYPE          ll_size_t;
typedef __LL_DEFAULT_RETURN_CODE_TYPE   ll_ret_code_t;

/// @brief Defination of linked-list's node
typedef struct ll_node_t{
    ll_data_t data;
    ll_size_t index;
    struct ll_node_t* next_node_ptr;
    struct ll_node_t* prev_node_ptr;
} ll_node_t;

/// @brief Defination of linked-list type
typedef struct linked_list_t{
    ll_node_t* root_node;  ;    // root node                (also head)
    ll_node_t* last_node_ptr;   // last pointed node        (also tail)
    ll_size_t size;     // size of ll 
} linked_list_t;

/// @brief Linked-list object
extern linked_list_t*    ll_ptr;

/// @brief Set previous node address of specified node
/// @param specified_node 
/// @param prev_node 
/// @return 
ll_node_t*      ll_set_prev_node_addr(  ll_node_t* specified_node, 
                                        ll_node_t* prev_node);

/// @brief Set next node address of specified node
/// @param specified_node 
/// @param next_node 
/// @return 
ll_node_t*      ll_set_next_node_addr(  ll_node_t* specified_node,
                                        ll_node_t* next_node);

/// @brief Set data node of specified node
/// @param specified_node 
/// @return 
ll_node_t*      ll_set_data_node(       ll_node_t* specified_node, 
                                        ll_data_t data);

/// @brief Set index node of specified node
/// @param specified_node 
/// @return 
ll_node_t*      ll_set_index_node(      ll_node_t* specified_node,
                                        ll_size_t index);

/// @brief Set data of specied node
/// @param specified_node
/// @param prev 
/// @param next 
/// @param index 
/// @param data 
/// @return specified_node (same as input)
ll_node_t*      ll_set_node(            ll_node_t* specified_node, 
                                        ll_node_t* prev, 
                                        ll_node_t* next, 
                                        ll_size_t index, 
                                        ll_data_t data);

/// @brief Create new linked-list's node with preserved data
/// @param prev_node 
/// @param next_node 
/// @param index 
/// @param data 
/// @return Address of new linked-list's node
ll_node_t*      ll_node_create(         ll_node_t* prev_node,
                                        ll_node_t* next_node,
                                        ll_size_t index,
                                        ll_data_t data);

/// @brief Add new node (<size+1>-th node) to linked-list
/// @param data 
/// @return Address of new node (tail)
ll_node_t*      ll_push_back(           ll_data_t data);

/// @brief Initialize linked-list
/// @param ll_size_init 
void            ll_init(                ll_size_t ll_size_init);

/// @brief Delete specified node
/// @param specified_node 
/// @return 0 - success | (-1) - failed (-1 in unsiged may be 1s' number)
ll_ret_code_t   ll_node_delete(         ll_node_t* specified_node);

/// @brief Remove last node
/// @return 0 - success | (-1)
ll_ret_code_t   ll_pop_back();

/// @brief Remove all nodes in the linked-list
ll_ret_code_t   ll_destroy();

/// @brief Get node at provided index
/// @param index 
/// @return NULL - not found | Address of matched index node
ll_node_t*      ll_node_at(             ll_size_t index);

/// @brief Get data bv index
/// @return data, if failed - return (-1)
ll_data_t       ll_data_at(             ll_size_t index);

/// @brief Get index of specified node
/// @param specifed_node 
ll_size_t       ll_index_at(            ll_node_t* specifed_node);

// ll_ret_code_t   ll_shift_right();

// ll_ret_code_t   ll_shift_left();

/// @brief Delete node with provided address
/// @param specified_node
/// @return Status of operation
ll_ret_code_t   ll_delete_node(         ll_node_t* specified_node);

/// @brief Delete node with provided index
/// @param index
/// @return Status of operation
ll_ret_code_t   ll_delete_node_index(   ll_size_t index);


#if defined(LOG) && defined(WRITE_LOG)
void            log_all_nodes();
#endif

#endif

