#include "glue_list.h"

void init_gluelist_head(gluelist_head_t *gluelist_head, uint32_t offset)
{
    gluelist_head->head = NULL;
    gluelist_head->offset = offset;
}

void init_gluelist_node(gluelist_node_t *glue_list_node)
{
    glue_list_node->p_next = NULL;
    glue_list_node->p_prev = NULL;
}

void gluelist_add_next(gluelist_node_t *curr_node, gluelist_node_t *new_node)
{
    if(!curr_node->p_next) {
        curr_node->p_next = new_node;
        new_node->p_prev = curr_node;
        return;
    }

    gluelist_node_t *temp = curr_node->p_next;
    curr_node->p_next = new_node;
    new_node->p_prev = curr_node;
    temp->p_prev = new_node;
}

void gluelist_add(gluelist_head_t *gluelist_head, gluelist_node_t *new_node)
{
    new_node->p_next = NULL;
    new_node->p_prev = NULL;

    if(!gluelist_head->head) {
        gluelist_head->head = new_node;
        return;
    }

    gluelist_node_t *temp_head = gluelist_head->head;
    gluelist_add_next(new_node, temp_head);
    gluelist_head->head = new_node;
}
