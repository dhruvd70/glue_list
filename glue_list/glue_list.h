#ifndef __GLUE_LIST__
#define __GLUE_LIST__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct gluelist_node_{
    struct gluelist_node_ *p_next;
    struct gluelist_node_ *p_prev;
}gluelist_node_t;

typedef struct gluelist_head_{
    gluelist_node_t *head;
    uint32_t offset;
}gluelist_head_t;

#define BASE(gluelist_ptr)  ((gluelist_ptr)->p_next)

#define ITERATE_GLUELIST_BEGIN(gluelist_head, struct_type, struct_ptr)        \
    {                                                                   \
        gluelist_node_t *temp_node = NULL, *temp_next = NULL;           \
        for(temp_node = gluelist_head->head;temp_node; temp_node = temp_next){            \
            temp_next = temp_node->p_next;                                              \
            struct_ptr = (struct_type *)((char *)temp_node - gluelist_head->offset);

#define ITERATE_GLUELIST_END }}                                                                  

#define GLUELIST_TO_STRUCT(fn_name, structure_name, field_name)         \
    static inline structure_name * fn_name(gluelist_node_t *glthreadptr){    \
        return (structure_name *)((char *)(glthreadptr) - (char *)&(((structure_name *)0)->field_name)); \
    }

#define OFFSET_OF(struct_name, field_name)          \
        ((uintptr_t)&((struct_name *)0)->field_name)

void init_gluelist_head(gluelist_head_t *gluelist_head, uint32_t offset);

void init_gluelist_node(gluelist_node_t *glue_list_node);

void gluelist_add(gluelist_head_t *gluelist_head, gluelist_node_t *new_node);

uint32_t get_gluelist_count(gluelist_node_t *glue_list_head);


#endif