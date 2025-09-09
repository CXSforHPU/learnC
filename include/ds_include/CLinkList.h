#ifndef _CLINKLIST_H
#define _CLINKLIST_H

#include "tools.h"

typedef struct CNode
{
    int data;
    struct CNode *next;
} CNode, *P_CNode;

typedef CNode *CLinkList;

// 函数声明
CLinkList Init_CLinkList();
int get_length_CLinkList(CLinkList h);
my_bool insert_head_CLinkList(CLinkList h, int x);
my_bool insert_tail_CLinkList(CLinkList h, int x);
my_bool delete_CLinkList_value(CLinkList h, int x);
my_bool delete_CLinkList_length(CLinkList h, int length);
void print_CLinkList(CLinkList h);
void select_sort_CLinkList(CLinkList h);


#endif //_CLINKLIST_H