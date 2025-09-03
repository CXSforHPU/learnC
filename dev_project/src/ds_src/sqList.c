#include "sqList.h"

#define MAX_TABLE_SIZE 10
#define TABLE_EXPEND_TIMES 2
/* 顺序表 */

/**
 * @brief 扩展表的长度，将表的容量扩大TABLE_EXPEND_TIMES倍
 * @param p_sqList - 指向表结构体的指针
 * @return 扩展成功返回TRUE，失败返回FALSE
 */
my_bool expend_length_sqList(P_sqList p_sqList)
{
    if (p_sqList == NULL)
    {
        printf("p_sqList is NULL!\n");
        return FALSE;
    }

    int old_size = p_sqList->size;
    int new_size = (old_size)*TABLE_EXPEND_TIMES;

    /* 重新分配内存空间，将容量扩展TABLE_EXPEND_TIMES倍 */
    int *new_head = (int *)realloc(p_sqList->head, new_size * sizeof(int));

    if (new_head == NULL)
    {
        printf("realloc fail!\n");
        return FALSE;
    }

    /* 将新分配的内存空间初始化为0 */
    memset(new_head + old_size, 0, (new_size - old_size) * sizeof(int));

    /* 更新表的大小信息 */

    p_sqList->head = new_head;
    p_sqList->size = new_size;

    return TRUE;
}

/**
 * @brief 初始化顺序表
 * @return 返回指向新创建顺序表的指针
 */
P_sqList Init_sqList()
{
    /* 分配内存以创建新的顺序表  */
    P_sqList table_point = (P_sqList)malloc(sizeof(sqList));

    table_point->head = (int *)malloc(MAX_TABLE_SIZE * sizeof(int));
    table_point->length = 0;
    table_point->size = MAX_TABLE_SIZE;

    /* 初始化数组元素为0 */
    memset(table_point->head, 0, sizeof(table_point->head));
}

/**
 * @brief 打印表格内容
 * @param p_sqList 指向表格结构体的指针，包含要打印的数据
 *                     - head: 指向数据数组的指针
 *                     - length: 表格中元素的个数
 * @return 无返回值
 */
void Print_sqList(P_sqList p_sqList)
{
    /* 遍历表格中的所有元素并打印 */
    for (int i = 0; i < p_sqList->length; i++)
    {
        printf("%d ", p_sqList->head[i]);
    }
    /* 打印完成后换行 */
    printf("\n");
}

/**
 * @brief 向表中添加元素
 * @param p_sqList 表结构体指针，包含表的头指针、长度和容量信息
 * @param x 要添加到表中的整型元素
 * @return 添加成功返回TRUE，失败返回FALSE
 */
my_bool add_sqList(P_sqList p_sqList, int x)
{
    /* 检查表是否已满，如果已满则尝试扩容 */
    if (p_sqList->length == p_sqList->size)
    {
        /* 扩容失败时输出错误信息并返回FALSE */
        if (!expend_length_sqList(p_sqList))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* 将新元素添加到表的末尾并更新长度 */
    p_sqList->head[p_sqList->length] = x;
    p_sqList->length++;
    return TRUE;
}

/**
 * @brief 从表中删除指定位置的元素
 * @param p_sqList 指向表结构的指针
 * @param Order 要删除元素的位置索引
 * @return 成功删除返回TRUE，索引越界返回FALSE
 */
my_bool remove_sqList_Order(P_sqList p_sqList, int Order)
{
    /* 检查索引范围 */
    if (Order < 0 || Order >= p_sqList->length)
    {
        return FALSE;
    }

    /* 删除元素,依次往前覆盖 */
    int index_start = LENGTH2INDEX(Order);
    int index_end = LENGTH2INDEX(p_sqList->length);
    for (int i = index_start; i <= index_end; i++)
    {
        p_sqList->head[i] = p_sqList->head[i + 1];
    }
    p_sqList->length--;

    return TRUE;
}

/**
 * @brief 在表的指定位置插入元素
 * @param p_sqList 表结构体指针，指向要操作的表
 * @param Order 插入位置的位序（从1开始计数）
 * @param x 要插入的元素值
 * @return 操作结果，TRUE表示成功，FALSE表示失败
 */
my_bool insert_sqList_order(P_sqList p_sqList, int Order, int x)
{
    /* 检查索引范围 */
    int length = p_sqList->length + 1;
    if (length < 0 || length > p_sqList->size)
    {
        if (!expend_length_sqList(p_sqList))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* 数据数量加一  */
    p_sqList->length++;

    /* 转换位序为索引 */
    int index_end = LENGTH2INDEX(Order);
    int index_start = LENGTH2INDEX(p_sqList->length);

    /* 在指定索引之后的元素都往前挪一位  */
    for (int i = index_start; i >= index_end; i--)
    {
        p_sqList->head[i + 1] = p_sqList->head[i];
    }

    /* 指定索引进行赋值覆盖原先数据 */
    p_sqList->head[index_end] = x;
}

/**
 * @brief 删除表结构及其关联的数据
 * @param p_sqList 指向要删除的表结构的指针
 * @return 无返回值
 */
my_bool delete_sqList(P_sqList p_sqList)
{
    /* 释放表头占用的内存 */
    free(p_sqList->head);
    /* 释放表结构本身占用的内存 */
    free(p_sqList);
}

