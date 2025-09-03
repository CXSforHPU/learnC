#include "tools.h"


/* 链表结构 */
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