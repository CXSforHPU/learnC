#include "CLinkList.h"

/**
 * 获取循环链表的长度
 * @param h 循环链表的头节点
 * @return 链表中节点的个数
 */
int get_length_CLinkList(CLinkList h) 
{
    int length = 0; 
    P_CNode p = h->next;
    while (p != h)
    {
        length++;
        p = p->next;
    }
    return length;
}

/**
 * 初始化一个空的循环链表
 * @return 指向新创建的循环链表头节点的指针，如果内存分配失败则返回NULL
 */
CLinkList Init_CLinkList() 
{ 
    CLinkList head = (CLinkList)malloc(sizeof(CNode));
    // 将头节点的next指向自己，构成循环结构
    head->next = head;
    // 头节点数据域设置为-1，表示无效数据
    head->data = -1;

    return head;
}

/**
 * 在循环链表头部插入一个新节点
 * @param h 循环链表的头节点
 * @param x 要插入的数据值
 * @return 插入成功返回TRUE，失败返回FALSE
 */
my_bool insert_head_CLinkList(CLinkList h, int x) 
{
    P_CNode q = (P_CNode)malloc(sizeof(CNode)); 
    if (q == NULL)
    {
        printf("内存分配失败\n");
        return FALSE;
    }
    
    q->data = x;
 
    // 将新节点插入到头节点之后
    q->next = h->next;
    h->next = q;

    return TRUE;
}

/**
 * 在循环链表尾部插入一个新节点
 * @param h 循环链表的头节点
 * @param x 要插入的数据值
 * @return 插入成功返回TRUE，失败返回FALSE
 */
my_bool insert_tail_CLinkList(CLinkList h, int x) 
{
    P_CNode q = (P_CNode)malloc(sizeof(CNode));
    P_CNode p = h;
    
    if (q == NULL)
    {
        printf("内存分配失败\n");
        return FALSE;
    }
    
    // 遍历到链表的最后一个节点
    while (p->next != h)
    {
        p = p->next;
    }

    // 在尾部插入新节点
    p->next = q;
    q->data = x;
    q->next = h;

    return TRUE;
}

/**
 * 删除循环链表中第一个值为x的节点
 * @param h 循环链表的头节点
 * @param x 要删除的节点值
 * @return 删除成功返回TRUE，未找到对应节点返回FALSE
 */
my_bool delete_CLinkList_value(CLinkList h, int x) 
{
    P_CNode p = h;
    // 遍历链表寻找要删除的节点
    while (p->next != h)
    {
        if (p->next->data == x)
        {
            P_CNode q = p->next;
            p->next = q->next;
            free(q);
            return TRUE;
        }
        p = p->next;
    }

    return FALSE;
}

/**
 * 删除循环链表中指定位置的节点
 * @param h 循环链表的头节点
 * @param length 要删除节点的位置（从1开始计数）
 * @return 删除成功返回TRUE，位置无效返回FALSE
 */
my_bool delete_CLinkList_length(CLinkList h, int length) 
{
    int max_length = get_length_CLinkList(h);
    if (length <= 0 || length > max_length)
    {
        printf("输入的length有误\n");
        return FALSE;
    }

    P_CNode p = h;
    while (p->next != h)
    {
        if (length == 1)
        {
            P_CNode q = p->next;
            p->next = q->next;
            free(q);
            return TRUE;
        }
        p = p->next;
        length--;
    } 
}

/**
 * 打印循环链表中的所有节点数据
 * @param h 循环链表的头节点
 */
void print_CLinkList(CLinkList h) 
{
    // 防御性编程：检查头节点是否为空
    if (h == NULL) {
        return;
    }

    P_CNode p = h->next;
    if (p == h)
    {
        printf("循环链表为空\n");
    }
    
    // 增加安全性：确保不会因为链表结构错误而陷入死循环
    while (p != h && p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 对循环链表进行选择排序
 * @param h 循环链表的头节点指针
 */
void select_sort_CLinkList(CLinkList h)
{
    // 如果链表为空或只有一个节点，则无需排序
    if (h == NULL || h->next == NULL)
    {
        return;
    }

    P_CNode i = h->next;

    // 外层循环：遍历每个未排序的节点
    while(i != h)
    {
        P_CNode min_node = i;  // 假设当前位置为最小值节点
        P_CNode j = i->next;   // 从下一个节点开始比较
        
        // 内层循环：在剩余未排序部分中寻找最小值节点
        while(j != h)
        {
            if (j->data < min_node->data)
            {
                min_node = j;  // 更新最小值节点
            }
            j = j->next;
        }

        // 如果找到更小的节点，则交换数据
        if (min_node != i)
        {
            swap_int(&i->data, &min_node->data);
        }
        
        i = i->next;  // 移动到下一个未排序节点
    }

}



