#include "alg.h"

#ifdef TEST_LEFT_MOVE
/**
 * @brief �����������ƶ�n��λ��
 *
 * �ú���ͨ�����η�ת����ʵ���������ƣ�
 * 1. ��תǰn��Ԫ��
 * 2. ��תʣ���Ԫ��
 * 3. ��ת��������
 *
 * @param array ָ�����������ָ��
 * @param length ����ĳ���
 * @param n ���Ƶ�λ����
 */
void left_move(int *array, int length, int n)
{
    int *a = array;
    int *b = array + n;
    reverse_array(a, n);          // ��תǰn��Ԫ��
    reverse_array(b, length - n); // ��ת�ӵ�n��Ԫ�ؿ�ʼ��ĩβ��Ԫ��
    reverse_array(array, length); // ��ת�������飬������Ʋ���
}

/**
 * ��ȡ�м����ֵ�����
 *
 * @param length ��������еĳ���
 *
 * @return �����м�λ�õ�����ֵ������ż�����ȷ��ؽ�С���м�����
 */
int get_middle_number_index(int length)
{
    return length / 2;
}

/**
 * ��ȡ������������ϲ������λ��
 * @param arr1: ��һ�����������ָ��
 * @param arr2: �ڶ������������ָ��
 * @param length1: ��һ������ĳ���
 * @param length2: �ڶ�������ĳ���
 * @return: ��������ϲ������λ��
 */
int get_two_arr_middle_number(int *arr1, int *arr2, int length1, int length2)
{
    // ʹ��˫ָ��ֱ�ָ�������������ʼλ��
    int *a1 = arr1;
    int *a2 = arr2;
    // ����ϲ����������λ������
    int middle_index = get_middle_number_index(length1 + length2);

    int num = 0;
    // ��������λ��λ�ã�ͨ���Ƚ���������Ԫ�ش�С��ģ��ϲ�����
    for (int i = 0, j = 0, z = 0; i <= middle_index; i++)
    {
        num = a1[j] <= a2[z] ? a1[j++] : a2[z++];
    }

    return num;
}
#endif