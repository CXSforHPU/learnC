#include "alg.h"

#ifdef TEST_LEFT_MOVE
/**
 * @brief 将数组向左移动n个位置
 *
 * 该函数通过三次反转操作实现数组左移：
 * 1. 反转前n个元素
 * 2. 反转剩余的元素
 * 3. 反转整个数组
 *
 * @param array 指向整型数组的指针
 * @param length 数组的长度
 * @param n 左移的位置数
 */
void left_move(int *array, int length, int n)
{
    int *a = array;
    int *b = array + n;
    reverse_array(a, n);          // 反转前n个元素
    reverse_array(b, length - n); // 反转从第n个元素开始到末尾的元素
    reverse_array(array, length); // 反转整个数组，完成左移操作
}

/**
 * 获取中间数字的索引
 *
 * @param length 数组或序列的长度
 *
 * @return 返回中间位置的索引值，对于偶数长度返回较小的中间索引
 */
int get_middle_number_index(int length)
{
    return length / 2;
}

/**
 * 获取两个有序数组合并后的中位数
 * @param arr1: 第一个有序数组的指针
 * @param arr2: 第二个有序数组的指针
 * @param length1: 第一个数组的长度
 * @param length2: 第二个数组的长度
 * @return: 两个数组合并后的中位数
 */
int get_two_arr_middle_number(int *arr1, int *arr2, int length1, int length2)
{
    // 使用双指针分别指向两个数组的起始位置
    int *a1 = arr1;
    int *a2 = arr2;
    // 计算合并后数组的中位数索引
    int middle_index = get_middle_number_index(length1 + length2);

    int num = 0;
    // 遍历到中位数位置，通过比较两个数组元素大小来模拟合并过程
    for (int i = 0, j = 0, z = 0; i <= middle_index; i++)
    {
        num = a1[j] <= a2[z] ? a1[j++] : a2[z++];
    }

    return num;
}
#endif


/**
 * 将两个循环链表连接在一起
 * 
 * 该函数将第二个循环链表h2连接到第一个循环链表h1的末尾，
 * 形成一个新的循环链表，新链表以h1为头节点。
 * 
 * @param h1 第一个循环链表的头节点指针
 * @param h2 第二个循环链表的头节点指针
 */
void concat_clinklist(CLinkList h1, CLinkList h2)
{
    // 检查输入有效性
    if (h1 == NULL || h2 == NULL) {
        return;
    }

    // 找到第一个循环链表h1的最后一个节点
    P_CNode p1 = h1;
    while (p1->next != h1) {
        p1 = p1->next;
    }

    // 找到第二个循环链表h2的最后一个节点
    P_CNode p2 = h2;
    while (p2->next != h2) {
        p2 = p2->next;
    }

    // 连接两个链表
    p1->next = h2->next; // h1的尾节点指向h2的第一个实际节点
    p2->next = h1;       // h2的尾节点指向h1的头节点，保持循环特性

    // 释放h2头节点内存（确保h2是通过malloc分配的）
    free(h2);
}

void test_concat_clinklist()
{
    print_horizontal_line(20);
    printf("测试连接两个循环链表\n");
    CLinkList h1 = Init_CLinkList();
    CLinkList h2 = Init_CLinkList();

    insert_tail_CLinkList(h1, 1);
    insert_tail_CLinkList(h1, 2);
    insert_tail_CLinkList(h1, 3);

    insert_tail_CLinkList(h2, 6);
    insert_tail_CLinkList(h2, 7);
    insert_tail_CLinkList(h2, 8);

    printf("h1: \n");
    print_CLinkList(h1);
    printf("h2: \n");
    print_CLinkList(h2);

    concat_clinklist(h1, h2);

    printf("拼接后\n");
    print_CLinkList(h1);

}


/**
 * 按升序删除循环链表中的所有节点
 * 
 * 该函数首先对循环链表进行选择排序，然后按升序依次删除所有节点。
 * 在删除前后会打印链表状态，最后释放头节点内存。
 * 
 * @param h 循环链表的头节点指针
 */
void del_clinklist_ascending_order(CLinkList h)
{
    // 对循环链表进行选择排序
    select_sort_CLinkList(h);
    
    // 获取链表长度
    int length = get_length_CLinkList(h);
    
    // 打印排序后的链表
    print_CLinkList(h);

    // 按升序依次删除所有节点（每次删除第一个节点）
    for (int i = 1; i <= length; i++)
    {
        delete_CLinkList_length(h, 1);
    }
    
    // 打印删除后的链表状态
    print_CLinkList(h);
    
    // 释放头节点内存
    free(h);
}

void test_del_clinklist_ascending_order()
{
    print_horizontal_line(20);
    printf("测试删除循环链表升序排列的元素\n");
    CLinkList h = Init_CLinkList();

    insert_tail_CLinkList(h, 5);
    insert_tail_CLinkList(h, 1);
    insert_tail_CLinkList(h, 2);
    insert_tail_CLinkList(h, 3);

    insert_tail_CLinkList(h, 6);
    insert_tail_CLinkList(h, 7);
    insert_tail_CLinkList(h, 8);
    printf("删除前h: \n");
    print_CLinkList(h);
    
    printf("删除后h: \n");
    del_clinklist_ascending_order(h);

}

void print_binary(size_t num)
{
    if (num == 0) {
        printf("0");
        return;
    }
    
    // 找到最高位
    size_t temp = num;
    int bits = 0;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    
/* 
从最高位开始打印
bits -1 表示位序0000 0000 0000 0000 0000 0000 0000 1010
0-31
1ULL 表示64位无符号整数 的1
1ULL << i 表示64位无符号整数 左移i位
*/
    for (int i = bits - 1; i >= 0; i--) {
        if (num & (1ULL << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}


size_t transform_ten2two(int num)
{
    size_t result =  0x0;

    int i = 0;
    while (num != 0)
    {
        if (num % 2 == 1)
        {
            result |= 0x1 << i;
        }
        i++;
        num /= 2;
    }

    return result;
}

void test_transform_ten2two()
{
    print_horizontal_line(20);
    printf("测试将十进制数转换成二进制数\n");
    int num = 0;
    size_t binary = transform_ten2two(num);
    printf("十进制数%d转换成二进制数：", num);
    print_binary(binary);
    printf("\n");
}
