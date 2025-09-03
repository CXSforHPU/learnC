#ifndef __DS_H__
#define __DS_H__

#include "config.h"
#include "my_type.h"

/* ˳��� */
typedef struct
{
    int *head;  // ����һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
    int length; // ��¼��ǰ˳����ĳ���
    int size;   // ��¼˳����Ĵ洢����
} sqList, *P_sqList;

my_bool expend_length_sqList(P_sqList p_sqList);
P_sqList Init_sqList();
void Print_sqList(P_sqList p_sqList);
my_bool add_sqList(P_sqList p_sqList, int x);
my_bool remove_sqList_Order(P_sqList p_sqList, int Order);
my_bool insert_sqList_order(P_sqList p_sqList, int Order, int x);
my_bool delete_sqList(P_sqList p_sqList);

/* �����ṹ */
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *P_LNode;

typedef LNode *LinkList;

LinkList init_list();
my_bool head_insect(LinkList h, int x);
int get_length(LinkList h);
my_bool tail_insect(LinkList h, int data);
P_LNode find_P_LNode_length(LinkList h, int length);
P_LNode find_P_LNode_value(LinkList h, int value);
void print_list(LinkList h);
my_bool delete_P_LNode_length(LinkList h, int length);
my_bool delete_P_LNode_value(LinkList h, int value);
my_bool insert_P_LNode_length(LinkList h, int length, int data);
my_bool free_nodes(LinkList h);
my_bool destroy_list(LinkList h);

#endif