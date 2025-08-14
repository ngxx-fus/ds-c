# About

A Linked-list library implemented in C. 

# Working-tree

    .
    ├── include
    │   └── DS
    │       ├── linked_list.c
    │       └── linked_list.h
    ├── readme.md
    ├── test
    └── test.c

# Custom

There're a lot of macros in `linked_list.h` and `linked_list.c`, that will help you custom the library. 

## Log

Logging is an important part of library development. I’m using the LOG macro to enable or disable logging in the library. Logging will be enabled if `LOG` is defined, regardless of its value. During development and testing, logs are written via the `WRITE_LOG` macro. Depending on your needs, `WRITE_LOG` can be replaced with a suitable function.

```C
#define LOG
#define WRITE_LOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
```

## Pre-defined macros

EXISTED_MACRO_WARNING is a macro that controls certain warning checks for pre-defined macros.
It will print a message while compiling the library.

```C
#define EXISTED_MARCO_WARNING
```
**NOTE:** You have to include the header file after all definition of macros.

## Datatype and default value

I love C++, with `vector<date_type>`, with OOP and quick declare anything. But in C is harder, we don't have any template<class T> to define template class. I borrow that from C++ via macro. All macros below is set-up date type and default value for the linked-list. 
```C
#define __LL_DEF_IVAL                   0
#define __LL_DEF_DVAL                   0
#define __LL_DEFAULT_DATA_TYPE          uint8_t 
#define __LL_DEFAULT_SIZE_TYPE          int32_t
#define __LL_DEFAULT_RETURN_CODE_TYPE   uint8_t
```

All datatype macros is re-defined via `typedef` (E.g: )

```C
typedef __LL_DEFAULT_DATA_TYPE          ll_data_t;
typedef __LL_DEFAULT_SIZE_TYPE          ll_size_t;
typedef __LL_DEFAULT_RETURN_CODE_TYPE   ll_ret_code_t;
```

# Structure

The linked-list is made from two general struct are `ll_node_t` and  `linked_list_t`; `linked_list_t` contain general information about the nodes insize the linked-list (head address, tail address, size). Meanwhile  ll_node_t contain information about neiborghs (prev-node address, next-node address) and its (data, index).

You can create multiple linked-list via create multiple linked_list_t pointers. But in this version, i dont pass any linked_list_t into the ll's function, all function operate on a global variable called `ll_ptr`. 

```C
/// @brief Definition of linked-list's node
typedef struct ll_node_t{
    ll_data_t data;
    ll_size_t index;
    struct ll_node_t* next_node_ptr;
    struct ll_node_t* prev_node_ptr;
} ll_node_t;

/// @brief Definition of linked-list type
typedef struct linked_list_t{
    ll_node_t* root_node;  ;    // root node                (also head)
    ll_node_t* last_node_ptr;   // last pointed node        (also tail)
    ll_size_t size;     // size of ll 
} linked_list_t;
```


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