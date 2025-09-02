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