#include "list.h"

/* 链表 */

/**
 * @brief 初始化一个链表
 * @return 指向新创建链表头节点的指针，如果创建失败则返回NULL
 */
head_pointer init_list()
{
    /* 分配内存以创建新的头节点 */
    head_pointer head = (head_pointer)malloc(sizeof(node));

    /* 检查内存分配是否成功 */
    if (head == NULL)
    {
        printf("creat fail!\n");
        return NULL;
    }

    /* 初始化头节点的数据和指针 */
    head->data = 0;
    head->next = NULL;

    return head;
}

/**
 * @brief 在带头结点的单链表头部插入新结点
 * @param h 链表的头指针
 * @param x 要插入的数据值
 * @return 操作成功返回TRUE，失败返回FALSE
 */
my_bool head_insect(head_pointer h, int x)
{
    /* 创建新结点 */
    node_pointer q = (node_pointer)malloc(sizeof(node));

    if (q == NULL)
    {
        printf("creat fail!\n");
        return FALSE;
    }
    /* 赋值 */
    q->data = x;

    /* 头插法插入结点 */
    q->next = h->next;
    h->next = q;

    return TRUE;
}

/**
 * @brief 打印链表中的所有元素
 * @param h 链表头节点的指针
 * @return 无返回值
 */
void print_list(head_pointer h)
{
    /* 遍历链表，从第一个有效节点开始 */
    node_pointer p = h->next;

    /* 依次打印每个节点的数据域 */
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    /* 打印换行符，使输出更清晰 */
    printf("\n");
}

/**
 * @brief 计算链表的长度
 * @param h 链表头指针
 * @return 链表中节点的个数
 */
int get_length(head_pointer h)
{
    int length = 0;
    node_pointer p = h;

    /* 遍历链表直到末尾，统计节点数量 */
    while (p->next != NULL)
    {
        length++;
        p = p->next;
    }

    return length;
}
/**
 * @brief 在链表尾部插入新节点
 * @param h 链表头指针
 * @param data 要插入的数据
 * @return 插入成功返回TRUE，失败返回FALSE
 */
my_bool tail_insect(head_pointer h, int data)
{
    node_pointer q = (node_pointer)malloc(sizeof(node));
    node_pointer p = h;
    if (q == NULL)
    {
        printf("creat fail!\n");
        return FALSE;
    }

    /* 赋值 */
    q->data = data;
    q->next = NULL;

    /* 找到最后一个节点 */
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = q;

    return TRUE;
}

/**
 * @brief 根据指定长度查找链表中的节点指针
 * @param h 链表的头指针
 * @param length 要查找的位置长度（从1开始计数）
 * @return 返回第length个节点的指针，如果超出范围则返回NULL
 */
node_pointer find_node_pointer_length(head_pointer h, int length)
{
    int max_length = get_length(h);

    /* 检查长度是否在有效范围内 */
    if (length < 0 || length > max_length)
    {
        return NULL;
    }
    else if (length == 0) /*返回头指针*/
    {
        return h;
    }

    int i = 1;
    node_pointer p = h;

    /* 遍历链表直到找到指定位置 */
    while (p->next != NULL && i <= length)
    {
        p = p->next;
        i++;
    }

    return p;
}

/**
 * @brief 在链表中查找具有指定值的节点
 * @param h 链表的头指针
 * @param value 要查找的值
 * @return 找到的节点指针，如果未找到则返回NULL
 */
node_pointer find_node_pointer_value(head_pointer h, int value)
{
    node_pointer p = h;

    /* 遍历链表查找目标值 */
    while (p->next != NULL)
    {
        if (p->data == value)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

/**
 * @brief 删除链表中指定位置的节点
 * @param h 链表头指针
 * @param length 要删除节点的位置（从1开始计数）
 * @return 删除成功返回TRUE，失败返回FALSE
 */
my_bool delete_node_pointer_length(head_pointer h, int length)
{
    node_pointer q = NULL;

    /* 查找要删除节点的前一个节点 */
    node_pointer p = find_node_pointer_length(h, length - 1);

    if (p == NULL)
    {
        return FALSE;
    }
    /* 删除节点 */
    q = p->next;
    p->next = q->next;
    free(q);

    return TRUE;
}

/**
 * @brief 从链表中删除指定值的节点
 * @param h 链表头节点指针
 * @param value 要删除的节点值
 * @return TRUE表示删除成功，FALSE表示未找到该值
 */
my_bool delete_node_pointer_value(head_pointer h, int value)
{
    node_pointer q = NULL;
    node_pointer p = h;

    /* 遍历链表查找要删除的节点 */
    while (p->next != NULL)
    {
        /* 检查下一个节点的下一个节点是否为目标值 */
        if (p->next->data == value)
        {
            /* 找到目标节点，执行删除操作 */
            q = p->next;
            p->next = q->next;
            free(q);
            return TRUE;
        }
        p = p->next;
    }

    return FALSE;
}

/**
 * @brief 在链表的指定位置插入新节点
 * @param h 链表头指针
 * @param length 插入位置（从1开始计数）
 * @param data 要插入的数据
 * @return 插入成功返回TRUE，失败返回FALSE
 */
my_bool insert_node_pointer_length(head_pointer h, int length, int data)
{
    /* 查找插入位置的前一个节点,找不到说明输入length不合理 */
    node_pointer p = find_node_pointer_length(h, length - 1);
    if (p == NULL)
    {
        return FALSE;
    }

    /* 分配新节点内存 */
    node_pointer q = (node_pointer)malloc(sizeof(node));

    if (q == NULL)
    {
        return FALSE;
    }

    /* 赋值 */
    q->data = data;

    /* 执行插入操作 */
    q->next = p->next; /* 下一个节点或者 NULL */
    p->next = q;

    return TRUE;
}

/**
 * @brief 释放链表中的所有节点
 * @param h 链表头指针
 * @return TRUE - 成功释放所有节点
 */
my_bool free_nodes(head_pointer h)
{
    node_pointer p = h->next;

    /* 循环释放节点 */
    while (p != NULL)
    {
        node_pointer q = p->next;
        free(p);
        p = q;
    }

    /* 需要设置NULL */
    h->next = NULL;
    return TRUE;
}

/**
 * @brief 销毁链表
 * @param h 链表头指针
 * @return 返回TRUE表示销毁成功
 */
my_bool destroy_list(head_pointer h)
{
    /* 释放所有节点内存 */
    free_nodes(h);
    /* 释放头指针内存 */
    free(h);
    return TRUE;
}