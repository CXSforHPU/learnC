#ifndef __DS_H__
#define __DS_H__

#include "config.h"
#include "my_type.h"

/* 链表结构 */
typedef struct node {
    int data;
    struct node* next;
} node, *node_pointer;

typedef node* head_pointer;

head_pointer init_list();
void head_insect(head_pointer h,int x);
void print_list(head_pointer h);


#endif