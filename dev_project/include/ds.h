#ifndef __DS_H__
#define __DS_H__

#include "config.h"
#include "my_type.h"

/* ˳��� */
typedef struct
{
    int *head;  // ����һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
    int length; // ��¼��ǰ˳���ĳ���
    int size;   // ��¼˳���Ĵ洢����
} Table, *Table_pointer;

my_bool expend_length_table(Table_pointer table_pointer);
Table_pointer InitTable();
void PrintTable(Table_pointer table_pointer);
my_bool add_table(Table_pointer table_pointer, int x);
my_bool remove_Order(Table_pointer table_pointer, int Order);
my_bool insert_table_order(Table_pointer table_pointer, int Order, int x);
my_bool delete_table(Table_pointer table_pointer);

/* ����ṹ */
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