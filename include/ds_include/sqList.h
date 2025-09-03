#include "tools.h"

/* 顺序表 */
typedef struct
{
    int *head;  // 定义一个名为head的长度不确定的数组，也叫“动态数组”
    int length; // 记录当前顺序表的长度
    int size;   // 记录顺序表的存储容量
} sqList, *P_sqList;

my_bool expend_length_sqList(P_sqList p_sqList);
P_sqList Init_sqList();
void Print_sqList(P_sqList p_sqList);
my_bool add_sqList(P_sqList p_sqList, int x);
my_bool remove_sqList_Order(P_sqList p_sqList, int Order);
my_bool insert_sqList_order(P_sqList p_sqList, int Order, int x);
my_bool delete_sqList(P_sqList p_sqList);

