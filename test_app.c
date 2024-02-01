#include <stdio.h>
#include "glue_list/glue_list.h"
#include <string.h>

typedef struct person_{
    char name[50];
    int person_id;
    gluelist_node_t glue_list_node;
}person_t;

GLUELIST_TO_STRUCT(list_to_person, person_t, glue_list_node);

int main()
{
    person_t *p1 = (person_t *)malloc(sizeof(person_t));
    strncpy(p1->name, "dhruv", sizeof("dhruv"));
    p1->person_id = 1001;
    init_gluelist_node(&p1->glue_list_node);

    person_t *p2 = (person_t *)malloc(sizeof(person_t));
    strncpy(p2->name, "swarni", sizeof("swarni"));
    p2->person_id = 1002;
    init_gluelist_node(&p2->glue_list_node);

    person_t *p3 = (person_t *)malloc(sizeof(person_t));
    strncpy(p3->name, "vipasana", sizeof("vipasana"));
    p3->person_id = 1003;
    init_gluelist_node(&p3->glue_list_node);

    person_t *p4 = (person_t *)malloc(sizeof(person_t));
    strncpy(p4->name, "kunal", sizeof("kunal"));
    p4->person_id = 1003;
    init_gluelist_node(&p4->glue_list_node);

    person_t *p5 = (person_t *)malloc(sizeof(person_t));
    strncpy(p5->name, "honey", sizeof("honey"));
    p5->person_id = 1004;
    init_gluelist_node(&p5->glue_list_node);

    gluelist_head_t *head = (gluelist_head_t *)malloc(sizeof(gluelist_head_t));
    init_gluelist_head(head, OFFSET_OF(person_t, glue_list_node));

    gluelist_add(head, &p1->glue_list_node);
    gluelist_add(head, &p2->glue_list_node);
    gluelist_add(head, &p3->glue_list_node);
    gluelist_add(head, &p4->glue_list_node);
    gluelist_add(head, &p5->glue_list_node);

    person_t* temp = NULL;

    ITERATE_GLUELIST_BEGIN(head,person_t, temp) {
        printf("NAME: %s, PERSON_ID: %d\n",temp->name, temp->person_id);
    }ITERATE_GLUELIST_END
    return 0;
}