#include "ds.h"
#include "tools.h"

/* 顺序表 */

/* 链表 */
head_pointer init_list()
{
    head_pointer head = (head_pointer)malloc(sizeof(node));

    if (head == NULL)
    {
        printf("creat fail!\n");
        return NULL;
    }
    
    head->data = 0;
    head->next = NULL;

    return head;
}

void head_insect(head_pointer h,int x)
{
    //带头
    node_pointer q = (node_pointer)malloc(sizeof(node));

    // 赋值
    q->data = x;

    //头插
    q->next = h->next;
    h->next = q;
}

void print_list(head_pointer h)
{

    node_pointer p = h->next;

    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");

}