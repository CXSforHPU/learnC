#include "table.h"

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

