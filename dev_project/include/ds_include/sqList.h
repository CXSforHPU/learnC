#include "tools.h"

/* ˳��� */
typedef struct
{
    int *head;  // ����һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
    int length; // ��¼��ǰ˳���ĳ���
    int size;   // ��¼˳���Ĵ洢����
} sqList, *P_sqList;

my_bool expend_length_sqList(P_sqList p_sqList);
P_sqList Init_sqList();
void Print_sqList(P_sqList p_sqList);
my_bool add_sqList(P_sqList p_sqList, int x);
my_bool remove_sqList_Order(P_sqList p_sqList, int Order);
my_bool insert_sqList_order(P_sqList p_sqList, int Order, int x);
my_bool delete_sqList(P_sqList p_sqList);

