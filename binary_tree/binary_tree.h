#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/// Un-comment two lines below enable LOG, and specify the actually log-function 
#define LOG
#define WRITE_LOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

/// Un-comment to enable defined macro warning
/// #define EXISTED_MARCO_WARNING

#ifndef LOG
#define WRITE_LOG(fmt, ...)
#endif

#define __BT_DEF_RET_TYPE           uint8_t
#define __BT_DEF_DATA_TYPE          uint8_t
#define __BT_DEF_SIZE_TYPE          int16_t

#define __BT_DEF_DATA_VAL           0
#define __BT_DEF_NODE_INDEX         0
#define __BT_DEF_NODE_DATE          0

typedef __BT_DEF_RET_TYPE           bt_ret_t;
typedef __BT_DEF_DATA_TYPE          bt_data_t; 
typedef __BT_DEF_SIZE_TYPE          bt_size_t;

typedef struct  bt_node_t {
    bt_size_t   index;
    bt_data_t   data;
    bt_node_t*  left;
    bt_node_t*  right;
} bt_node_t;

typedef struct  binary_tree_t {
    bt_node_t*  root;
    bt_size_t   size;
} binary_tree_t;

bt_node_t*      bt_modify_node(     bt_node_t* left,
                                    bt_node_t* right,
                                    bt_data_t  data);

bt_node_t*      bt_create_node(     bt_node_t* left,
                                    bt_node_t* right,
                                    bt_data_t  data);

