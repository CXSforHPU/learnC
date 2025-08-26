#ifndef __DS_H__
#define __DS_H__

#include "config.h"
#include "my_type.h"

/* 链表结构 */
typedef struct node
{
    int data;
    struct node *next;
} node, *node_pointer;

typedef node *head_pointer;

head_pointer init_list();
my_bool head_insect(head_pointer h, int x);
int get_length(head_pointer h);
my_bool tail_insect(head_pointer h, int data);
node_pointer find_node_pointer_length(head_pointer h, int length);
node_pointer find_node_pointer_value(head_pointer h, int value);
void print_list(head_pointer h);
my_bool delete_node_pointer_length(head_pointer h, int length);
my_bool delete_node_pointer_value(head_pointer h, int value);
my_bool insert_node_pointer_length(head_pointer h, int length, int data);
my_bool free_nodes(head_pointer h);
my_bool destroy_list(head_pointer h);

#endif