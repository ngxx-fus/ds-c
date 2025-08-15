#include "binary_tree.h"

#define bt_nd_left(node)    (node->left) 
#define bt_nd_right(node)   (node->right) 
#define bt_nd_data(node)    (node->data) 
#define bt_nd_index(node)   (node->index) 
#define __is_leaf(node)     (((node)->left == NULL) && (((node)->right)==NULL))
#define __is_null(what)     ((what)==NULL)
#define __not_null(what)    ((what)!=NULL)
#define __unknown_err       ((bt_ret_t)(-1))
#define __null_err          ((bt_ret_t)(-2))

bt_node_t*      bt_modify_node(     bt_node_t* specified_node,
                                    const bt_node_t* left,
                                    const bt_node_t* right,
                                    const bt_size_t  index,
                                    const bt_data_t  data)
{
    bt_nd_left(specified_node) = left;
    bt_nd_right(specified_node) = right;
    bt_nd_index(specified_node) = index;
    bt_nd_data(specified_node) = data;
    return specified_node;
}

bt_node_t*      bt_create_node(     const bt_node_t* left,
                                    const bt_node_t* right,
                                    const bt_size_t  index,
                                    const bt_data_t  data)
{
    return bt_modify_node(
        (bt_node_t*) malloc(sizeof(bt_node_t)),
        left,
        right,
        index,
        data
    );
}

bt_ret_t        bt_copy_node(       const bt_node_t* src,
                                    bt_node_t* dest)
{
    if (__is_null(src) || __is_null(dest)) return __null_err;
    bt_nd_left(dest)  = bt_nd_left(src);
    bt_nd_right(dest) = bt_nd_right(src);
    bt_nd_index(dest) = bt_nd_index(src);
    bt_nd_data(dest)  = bt_nd_data(src);
    return 0;
}