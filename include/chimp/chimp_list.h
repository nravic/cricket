#ifndef _CHIMP_LIST_H_
#define _CHIMP_LIST_H_

#include <stdbool.h>

#define CHIMP_LIST_INIT_SIZE 128

typedef struct chimp_list {
    chimp_list_elem_t *arr;
    size_t size;
    size_t alloc_size;
} chimp_list_t;

typedef struct chimp_list_elem {
    enum chimp_list_func func;
    void *ptr;
    size_t mem_size;
} chimp_list_elem_t;

enum chimp_list_func {
    FUNC_MALLOC,
    FUNC_FREE,
}

bool chimp_list_init(chimp_list_t *list);
void chimp_list_free(chimp_list_t *list);

bool chimp_list_add(chimp_list_t *list, chimp_list_elem_t elem);
bool chimp_list_add(chimp_list_t *list, enum chimp_list_func func,
                    void *ptr, size_t mem_size);
bool chimp_list_compress(chimp_list_t *list);


#endif //_CHIMP_LIST_H_
