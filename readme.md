# About

A Linked-list library write on C. 

# Working-tree

    .
    ├── include
    │   └── DS
    │       ├── linked_list.c
    │       └── linked_list.h
    ├── readme.md
    ├── test
    └── test.c

# Methods

| return | name | params | description |
|---|---|---|---|
| `ll_node_t*` | `ll_set_prev_node_addr` | `ll_node_t* specified_node`, `ll_node_t* prev_node` | Sets the previous node address for a specified node. |
| `ll_node_t*` | `ll_set_next_node_addr` | `ll_node_t* specified_node`, `ll_node_t* next_node` | Sets the next node address for a specified node. |
| `ll_node_t*` | `ll_set_data_node` | `ll_node_t* specified_node`, `ll_data_t data` | Sets the data value of a specified node. |
| `ll_node_t*` | `ll_set_index_node` | `ll_node_t* specified_node`, `ll_size_t index` | Sets the index value of a specified node. |
| `ll_node_t*` | `ll_set_node` | `ll_node_t* specified_node`, `ll_node_t* prev`, `ll_node_t* next`, `ll_size_t index`, `ll_data_t data` | Sets all properties (previous, next, index, and data) for a specified node. Returns the address of the specified node. |
| `ll_node_t*` | `ll_node_create` | `ll_node_t* prev_node`, `ll_node_t* next_node`, `ll_size_t index`, `ll_data_t data` | Creates a new linked list node with the provided data and links it to the previous and next nodes. Returns the address of the new node. |
| `ll_node_t*` | `ll_push_back` | `ll_data_t data` | Adds a new node with the given data to the end of the linked list. Returns the address of the new node (the new tail). |
| `void` | `ll_init` | `ll_size_t ll_size_init` | Initializes the linked list with a specified initial size. |
| `ll_ret_code_t` | `ll_node_delete` | `ll_node_t* specified_node` | Deletes a specified node from the linked list. Returns a status code (0 for success, -1 for failure). |
| `ll_ret_code_t` | `ll_pop_back` | None | Removes the last node from the linked list. Returns a status code (0 for success, -1 for failure). |
| `ll_ret_code_t` | `ll_destroy` | None | Deletes all nodes and frees all memory allocated for the linked list. |
| `ll_node_t*` | `ll_node_at` | `ll_size_t index` | Retrieves the node at a given index. Returns `NULL` if the index is not found. |
| `ll_data_t` | `ll_data_at` | `ll_size_t index` | Retrieves the data from the node at a given index. Returns `-1` if the operation fails. |
| `ll_size_t` | `ll_index_at` | `ll_node_t* specifed_node` | Retrieves the index of a specified node. |
| `ll_ret_code_t` | `ll_delete_node` | `ll_node_t* specified_node` | Deletes a node using its memory address. Returns a status code. |
| `ll_ret_code_t` | `ll_delete_node_index` | `ll_size_t index` | Deletes a node using its index. Returns a status code. |
| `void` | `log_all_nodes` | None | (Conditional) Prints the details of all nodes in the linked list to the console. This function is only available if the `LOG` and `WRITE_LOG` macros are defined. |

# Structures

    ll_node_t
    ├── data            : (ll_data_t) The stored data value for this node.
    ├── index           : (ll_size_t) The position/index of this node in the list.
    ├── next_node_ptr   : (struct ll_node_t*) Pointer to the next node (NULL if tail).
    └── prev_node_ptr   : (struct ll_node_t*) Pointer to the previous node (NULL if head).

    linked_list_t
    ├── root_node       : (ll_node_t*) Pointer to the first node (head) in the list.
    ├── last_node_ptr   : (ll_node_t*) Pointer to the last node (tail) in the list.
    └── size            : (ll_size_t) Total number of nodes currently in the list.
