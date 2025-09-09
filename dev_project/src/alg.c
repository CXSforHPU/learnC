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


/**
 * ������ѭ������������һ��
 * 
 * �ú������ڶ���ѭ������h2���ӵ���һ��ѭ������h1��ĩβ��
 * �γ�һ���µ�ѭ��������������h1Ϊͷ�ڵ㡣
 * 
 * @param h1 ��һ��ѭ�������ͷ�ڵ�ָ��
 * @param h2 �ڶ���ѭ�������ͷ�ڵ�ָ��
 */
void concat_clinklist(CLinkList h1, CLinkList h2)
{
    // ���������Ч��
    if (h1 == NULL || h2 == NULL) {
        return;
    }

    // �ҵ���һ��ѭ������h1�����һ���ڵ�
    P_CNode p1 = h1;
    while (p1->next != h1) {
        p1 = p1->next;
    }

    // �ҵ��ڶ���ѭ������h2�����һ���ڵ�
    P_CNode p2 = h2;
    while (p2->next != h2) {
        p2 = p2->next;
    }

    // ������������
    p1->next = h2->next; // h1��β�ڵ�ָ��h2�ĵ�һ��ʵ�ʽڵ�
    p2->next = h1;       // h2��β�ڵ�ָ��h1��ͷ�ڵ㣬����ѭ������

    // �ͷ�h2ͷ�ڵ��ڴ棨ȷ��h2��ͨ��malloc����ģ�
    free(h2);
}

void test_concat_clinklist()
{
    print_horizontal_line(20);
    printf("������������ѭ������\n");
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

    printf("ƴ�Ӻ�\n");
    print_CLinkList(h1);

}


/**
 * ������ɾ��ѭ�������е����нڵ�
 * 
 * �ú������ȶ�ѭ���������ѡ������Ȼ����������ɾ�����нڵ㡣
 * ��ɾ��ǰ����ӡ����״̬������ͷ�ͷ�ڵ��ڴ档
 * 
 * @param h ѭ�������ͷ�ڵ�ָ��
 */
void del_clinklist_ascending_order(CLinkList h)
{
    // ��ѭ���������ѡ������
    select_sort_CLinkList(h);
    
    // ��ȡ������
    int length = get_length_CLinkList(h);
    
    // ��ӡ����������
    print_CLinkList(h);

    // ����������ɾ�����нڵ㣨ÿ��ɾ����һ���ڵ㣩
    for (int i = 1; i <= length; i++)
    {
        delete_CLinkList_length(h, 1);
    }
    
    // ��ӡɾ���������״̬
    print_CLinkList(h);
    
    // �ͷ�ͷ�ڵ��ڴ�
    free(h);
}

void test_del_clinklist_ascending_order()
{
    print_horizontal_line(20);
    printf("����ɾ��ѭ�������������е�Ԫ��\n");
    CLinkList h = Init_CLinkList();

    insert_tail_CLinkList(h, 5);
    insert_tail_CLinkList(h, 1);
    insert_tail_CLinkList(h, 2);
    insert_tail_CLinkList(h, 3);

    insert_tail_CLinkList(h, 6);
    insert_tail_CLinkList(h, 7);
    insert_tail_CLinkList(h, 8);
    printf("ɾ��ǰh: \n");
    print_CLinkList(h);
    
    printf("ɾ����h: \n");
    del_clinklist_ascending_order(h);

}

void print_binary(size_t num)
{
    if (num == 0) {
        printf("0");
        return;
    }
    
    // �ҵ����λ
    size_t temp = num;
    int bits = 0;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    
/* 
�����λ��ʼ��ӡ
bits -1 ��ʾλ��0000 0000 0000 0000 0000 0000 0000 1010
0-31
1ULL ��ʾ64λ�޷������� ��1
1ULL << i ��ʾ64λ�޷������� ����iλ
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
    printf("���Խ�ʮ������ת���ɶ�������\n");
    int num = 10;
    size_t binary = transform_ten2two(num);
    printf("ʮ������%dת���ɶ���������", num);
    print_binary(binary);
    printf("\n");
}
