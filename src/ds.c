#include "ds.h"
#include "tools.h"

#define MAX_TABLE_SIZE 10
#define TABLE_EXPEND_TIMES 2
/* 顺序表 */

/**
 * @brief 扩展表的长度，将表的容量扩大TABLE_EXPEND_TIMES倍
 * @param table_pointer - 指向表结构体的指针
 * @return 扩展成功返回TRUE，失败返回FALSE
 */
my_bool expend_length_table(Table_pointer table_pointer)
{
    if (table_pointer == NULL)
    {
        printf("table_pointer is NULL!\n");
        return FALSE;
    }

    int old_size = table_pointer->size;
    int new_size = (old_size)*TABLE_EXPEND_TIMES;

    /* 重新分配内存空间，将容量扩展TABLE_EXPEND_TIMES倍 */
    int *new_head = (int *)realloc(table_pointer->head, new_size * sizeof(int));

    if (new_head == NULL)
    {
        printf("realloc fail!\n");
        return FALSE;
    }

    /* 将新分配的内存空间初始化为0 */
    memset(new_head + old_size, 0, (new_size - old_size) * sizeof(int));

    /* 更新表的大小信息 */

    table_pointer->head = new_head;
    table_pointer->size = new_size;

    return TRUE;
}

/**
 * @brief 初始化顺序表
 * @return 返回指向新创建顺序表的指针
 */
Table_pointer InitTable()
{
    /* 分配内存以创建新的顺序表  */
    Table_pointer table_point = (Table_pointer)malloc(sizeof(Table));

    table_point->head = (int *)malloc(MAX_TABLE_SIZE * sizeof(int));
    table_point->length = 0;
    table_point->size = MAX_TABLE_SIZE;

    /* 初始化数组元素为0 */
    memset(table_point->head, 0, sizeof(table_point->head));
}

/**
 * @brief 打印表格内容
 * @param table_pointer 指向表格结构体的指针，包含要打印的数据
 *                     - head: 指向数据数组的指针
 *                     - length: 表格中元素的个数
 * @return 无返回值
 */
void PrintTable(Table_pointer table_pointer)
{
    /* 遍历表格中的所有元素并打印 */
    for (int i = 0; i < table_pointer->length; i++)
    {
        printf("%d ", table_pointer->head[i]);
    }
    /* 打印完成后换行 */
    printf("\n");
}

/**
 * @brief 向表中添加元素
 * @param table_pointer 表结构体指针，包含表的头指针、长度和容量信息
 * @param x 要添加到表中的整型元素
 * @return 添加成功返回TRUE，失败返回FALSE
 */
my_bool add_table(Table_pointer table_pointer, int x)
{
    /* 检查表是否已满，如果已满则尝试扩容 */
    if (table_pointer->length == table_pointer->size)
    {
        /* 扩容失败时输出错误信息并返回FALSE */
        if (!expend_length_table(table_pointer))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* 将新元素添加到表的末尾并更新长度 */
    table_pointer->head[table_pointer->length] = x;
    table_pointer->length++;
    return TRUE;
}

/**
 * @brief 从表中删除指定位置的元素
 * @param table_pointer 指向表结构的指针
 * @param Order 要删除元素的位置索引
 * @return 成功删除返回TRUE，索引越界返回FALSE
 */
my_bool remove_Order(Table_pointer table_pointer, int Order)
{
    /* 检查索引范围 */
    if (Order < 0 || Order >= table_pointer->length)
    {
        return FALSE;
    }

    /* 删除元素,依次往前覆盖 */
    int index_start = LENGTH2INDEX(Order);
    int index_end = LENGTH2INDEX(table_pointer->length);
    for (int i = index_start; i <= index_end; i++)
    {
        table_pointer->head[i] = table_pointer->head[i + 1];
    }
    table_pointer->length--;

    return TRUE;
}

/**
 * @brief 在表的指定位置插入元素
 * @param table_pointer 表结构体指针，指向要操作的表
 * @param Order 插入位置的位序（从1开始计数）
 * @param x 要插入的元素值
 * @return 操作结果，TRUE表示成功，FALSE表示失败
 */
my_bool insert_table_order(Table_pointer table_pointer, int Order, int x)
{
    /* 检查索引范围 */
    int length = table_pointer->length + 1;
    if (length < 0 || length > table_pointer->size)
    {
        if (!expend_length_table(table_pointer))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* 数据数量加一  */
    table_pointer->length++;

    /* 转换位序为索引 */
    int index_end = LENGTH2INDEX(Order);
    int index_start = LENGTH2INDEX(table_pointer->length);

    /* 在指定索引之后的元素都往前挪一位  */
    for (int i = index_start; i >= index_end; i--)
    {
        table_pointer->head[i + 1] = table_pointer->head[i];
    }

    /* 指定索引进行赋值覆盖原先数据 */
    table_pointer->head[index_end] = x;
}

/**
 * @brief 删除表结构及其关联的数据
 * @param table_pointer 指向要删除的表结构的指针
 * @return 无返回值
 */
my_bool delete_table(Table_pointer table_pointer)
{
    /* 释放表头占用的内存 */
    free(table_pointer->head);
    /* 释放表结构本身占用的内存 */
    free(table_pointer);
}

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