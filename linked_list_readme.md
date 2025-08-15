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

## Structures

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

## Reading the source code

The code in linked list.c is a bit confusing due to the use of macros to refer to properties (variables) in the struct.

```C
#define ll_nd_next(node)   ((node)->next_node_ptr) 
#define ll_nd_prev(node)   ((node)->prev_node_ptr)
#define ll_nd_data(node)       ((node)->data)
#define ll_nd_index(node)      ((node)->index)

#define ll_root(linked_list_p) ((linked_list_p)->root_node)
#define ll_head(linked_list_p) ((linked_list_p)->root_node)
#define ll_tail(linked_list_p) ((linked_list_p)->last_node_ptr)
#define ll_size(linked_list_p) ((linked_list_p)->size)

/// @brief Delete a node based on INDEX information, using macro
ll_ret_code_t   ll_delete_node_index(   ll_size_t index){
    WRITE_LOG("[LL-LOG] ll_delete_node_index(%d)", index);
    ll_node_t* temp_node = ll_root(ll_ptr);
    while( temp_node ){
        if (ll_nd_index(temp_node) == index){
            ll_delete_node(temp_node);
            return 0;
        }else{
            temp_node = ll_nd_next(temp_node);
        }
    }
    return -1;
}

/// @brief Delete a node based on INDEX information, normal



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


# Compile and run

You need compile .c file in the library before main.c file, if the order is inverted, the linker can not find where defined of a function or can not find symbol. If you had modified the source, but get error while compiling, may be the `include-path` is missing, you can specify it via `-I` flag (E.g: `-I include`).


```ZSH
clear; 
g++ \
-I include \
linked_list.c \
test_linked_list.c \
-o test_linked_list \
&& valgrind --leak-check=full -s ./test_linked_list
```

# Log

```LOG
==26215== Memcheck, a memory error detector
==26215== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==26215== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
==26215== Command: ./test
==26215==
----- Test LINKED-LIST program -----
[LL-LOG] ll_init(10)
[LL-LOG] ll_node_create((nil), (nil), 0, 0)
[LL-LOG] ll_set_node(0x4e91520, (nil), (nil), 0, 0)
[LL-LOG] ll_node_create(0x4e91520, (nil), 1, 0)
[LL-LOG] ll_set_node(0x4e91580, 0x4e91520, (nil), 1, 0)
[LL-LOG] ll_node_create(0x4e91580, (nil), 2, 0)
[LL-LOG] ll_set_node(0x4e915e0, 0x4e91580, (nil), 2, 0)
[LL-LOG] ll_node_create(0x4e915e0, (nil), 3, 0)
[LL-LOG] ll_set_node(0x4e91640, 0x4e915e0, (nil), 3, 0)
[LL-LOG] ll_node_create(0x4e91640, (nil), 4, 0)
[LL-LOG] ll_set_node(0x4e916a0, 0x4e91640, (nil), 4, 0)
[LL-LOG] ll_node_create(0x4e916a0, (nil), 5, 0)
[LL-LOG] ll_set_node(0x4e91700, 0x4e916a0, (nil), 5, 0)
[LL-LOG] ll_node_create(0x4e91700, (nil), 6, 0)
[LL-LOG] ll_set_node(0x4e91760, 0x4e91700, (nil), 6, 0)
[LL-LOG] ll_node_create(0x4e91760, (nil), 7, 0)
[LL-LOG] ll_set_node(0x4e917c0, 0x4e91760, (nil), 7, 0)
[LL-LOG] ll_node_create(0x4e917c0, (nil), 8, 0)
[LL-LOG] ll_set_node(0x4e91820, 0x4e917c0, (nil), 8, 0)
[LL-LOG] ll_node_create(0x4e91820, (nil), 9, 0)
[LL-LOG] ll_set_node(0x4e91880, 0x4e91820, (nil), 9, 0)
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91520[0|0]-->0x4e91580
[LL-LOG] log_all_nodes() | 0x4e91520<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e91760
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e91760[6|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91760<--0x4e917c0[7|0]-->0x4e91820
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e91820[8|0]-->0x4e91880
[LL-LOG] log_all_nodes() | 0x4e91820<--0x4e91880[9|0]-->(nil)
[LL-LOG] ll_delete_node_index(6)
[LL-LOG] ll_delete_node(0x4e91760)
[LL-LOG] ll_delete_node() | set-pointer: 0x4e91700-->0x4e917c0
[LL-LOG] ll_delete_node() | set-pointer: 0x4e91700<--0x4e917c0
[LL-LOG] ll_delete_node() | Update ll-size
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91520[0|0]-->0x4e91580
[LL-LOG] log_all_nodes() | 0x4e91520<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->0x4e91820
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e91820[8|0]-->0x4e91880
[LL-LOG] log_all_nodes() | 0x4e91820<--0x4e91880[9|0]-->(nil)
[LL-LOG] ll_delete_node_index(9)
[LL-LOG] ll_delete_node(0x4e91880)
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e91880
[LL-LOG] ll_pop_back() | ll_size=8
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91520[0|0]-->0x4e91580
[LL-LOG] log_all_nodes() | 0x4e91520<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->0x4e91820
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e91820[8|0]-->(nil)
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e91820
[LL-LOG] ll_pop_back() | ll_size=7
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91520[0|0]-->0x4e91580
[LL-LOG] log_all_nodes() | 0x4e91520<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->(nil)
[LL-LOG] ll_push_back(172)
[LL-LOG] ll_node_create(0x4e917c0, (nil), 8, 172)
[LL-LOG] ll_set_node(0x4e918e0, 0x4e917c0, (nil), 8, 172)
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91520[0|0]-->0x4e91580
[LL-LOG] log_all_nodes() | 0x4e91520<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->0x4e918e0
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e918e0[8|172]-->(nil)
[LL-LOG] ll_delete_node_index(0)
[LL-LOG] ll_delete_node(0x4e91520)
[LL-LOG] ll_delete_node() | Update ll-size
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->0x4e918e0
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e918e0[8|172]-->(nil)
[LL-LOG] ll_push_back(17)
[LL-LOG] ll_node_create(0x4e918e0, (nil), 9, 17)
[LL-LOG] ll_set_node(0x4e91940, 0x4e918e0, (nil), 9, 17)
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->0x4e918e0
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e918e0[8|172]-->0x4e91940
[LL-LOG] log_all_nodes() | 0x4e918e0<--0x4e91940[9|17]-->(nil)
[LL-LOG] ll_delete_node_index(15)
[LL-LOG] log_all_nodes()
[LL-LOG] log_all_nodes() | (nil)<--0x4e91580[1|0]-->0x4e915e0
[LL-LOG] log_all_nodes() | 0x4e91580<--0x4e915e0[2|0]-->0x4e91640
[LL-LOG] log_all_nodes() | 0x4e915e0<--0x4e91640[3|0]-->0x4e916a0
[LL-LOG] log_all_nodes() | 0x4e91640<--0x4e916a0[4|0]-->0x4e91700
[LL-LOG] log_all_nodes() | 0x4e916a0<--0x4e91700[5|0]-->0x4e917c0
[LL-LOG] log_all_nodes() | 0x4e91700<--0x4e917c0[7|0]-->0x4e918e0
[LL-LOG] log_all_nodes() | 0x4e917c0<--0x4e918e0[8|172]-->0x4e91940
[LL-LOG] log_all_nodes() | 0x4e918e0<--0x4e91940[9|17]-->(nil)
[LL-LOG] ll_destroy()
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e91940
[LL-LOG] ll_pop_back() | ll_size=7
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e918e0
[LL-LOG] ll_pop_back() | ll_size=6
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e917c0
[LL-LOG] ll_pop_back() | ll_size=5
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e91700
[LL-LOG] ll_pop_back() | ll_size=4
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e916a0
[LL-LOG] ll_pop_back() | ll_size=3
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e91640
[LL-LOG] ll_pop_back() | ll_size=2
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e915e0
[LL-LOG] ll_pop_back() | ll_size=1
[LL-LOG] ll_pop_back()
[LL-LOG] ll_pop_back() | To be del: 0x4e91580
[LL-LOG] ll_pop_back() | 0x4e91580 is ROOT/HEAD node!
[LL-LOG] ll_pop_back() | ll_size=0
[LL-LOG] ll_pop_back()
[LL-LOG] ll_destroy() | Deleted all nodes
==26215==
==26215== HEAP SUMMARY:
==26215==     in use at exit: 0 bytes in 0 blocks
==26215==   total heap usage: 15 allocs, 15 frees, 75,064 bytes allocated
==26215==
==26215== All heap blocks were freed -- no leaks are possible
==26215==
==26215== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```