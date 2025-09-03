#include "ds.h"

/* 顺序表 */
typedef struct
{
    int *head;  // 定义一个名为head的长度不确定的数组，也叫“动态数组”
    int length; // 记录当前顺序表的长度
    int size;   // 记录顺序表的存储容量
} Table, *Table_pointer;

my_bool expend_length_table(Table_pointer table_pointer);
Table_pointer InitTable();
void PrintTable(Table_pointer table_pointer);
my_bool add_table(Table_pointer table_pointer, int x);
my_bool remove_Order(Table_pointer table_pointer, int Order);
my_bool insert_table_order(Table_pointer table_pointer, int Order, int x);
my_bool delete_table(Table_pointer table_pointer);

