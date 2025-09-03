#include "sqList.h"

#define MAX_TABLE_SIZE 10
#define TABLE_EXPEND_TIMES 2
/* ˳��� */

/**
 * @brief ��չ��ĳ��ȣ��������������TABLE_EXPEND_TIMES��
 * @param p_sqList - ָ���ṹ���ָ��
 * @return ��չ�ɹ�����TRUE��ʧ�ܷ���FALSE
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

    /* ���·����ڴ�ռ䣬��������չTABLE_EXPEND_TIMES�� */
    int *new_head = (int *)realloc(p_sqList->head, new_size * sizeof(int));

    if (new_head == NULL)
    {
        printf("realloc fail!\n");
        return FALSE;
    }

    /* ���·�����ڴ�ռ��ʼ��Ϊ0 */
    memset(new_head + old_size, 0, (new_size - old_size) * sizeof(int));

    /* ���±�Ĵ�С��Ϣ */

    p_sqList->head = new_head;
    p_sqList->size = new_size;

    return TRUE;
}

/**
 * @brief ��ʼ��˳���
 * @return ����ָ���´���˳����ָ��
 */
P_sqList Init_sqList()
{
    /* �����ڴ��Դ����µ�˳���  */
    P_sqList table_point = (P_sqList)malloc(sizeof(sqList));

    table_point->head = (int *)malloc(MAX_TABLE_SIZE * sizeof(int));
    table_point->length = 0;
    table_point->size = MAX_TABLE_SIZE;

    /* ��ʼ������Ԫ��Ϊ0 */
    memset(table_point->head, 0, sizeof(table_point->head));
}

/**
 * @brief ��ӡ�������
 * @param p_sqList ָ����ṹ���ָ�룬����Ҫ��ӡ������
 *                     - head: ָ�����������ָ��
 *                     - length: �����Ԫ�صĸ���
 * @return �޷���ֵ
 */
void Print_sqList(P_sqList p_sqList)
{
    /* ��������е�����Ԫ�ز���ӡ */
    for (int i = 0; i < p_sqList->length; i++)
    {
        printf("%d ", p_sqList->head[i]);
    }
    /* ��ӡ��ɺ��� */
    printf("\n");
}

/**
 * @brief ��������Ԫ��
 * @param p_sqList ��ṹ��ָ�룬�������ͷָ�롢���Ⱥ�������Ϣ
 * @param x Ҫ��ӵ����е�����Ԫ��
 * @return ��ӳɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool add_sqList(P_sqList p_sqList, int x)
{
    /* �����Ƿ���������������������� */
    if (p_sqList->length == p_sqList->size)
    {
        /* ����ʧ��ʱ���������Ϣ������FALSE */
        if (!expend_length_sqList(p_sqList))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* ����Ԫ����ӵ����ĩβ�����³��� */
    p_sqList->head[p_sqList->length] = x;
    p_sqList->length++;
    return TRUE;
}

/**
 * @brief �ӱ���ɾ��ָ��λ�õ�Ԫ��
 * @param p_sqList ָ���ṹ��ָ��
 * @param Order Ҫɾ��Ԫ�ص�λ������
 * @return �ɹ�ɾ������TRUE������Խ�緵��FALSE
 */
my_bool remove_sqList_Order(P_sqList p_sqList, int Order)
{
    /* ���������Χ */
    if (Order < 0 || Order >= p_sqList->length)
    {
        return FALSE;
    }

    /* ɾ��Ԫ��,������ǰ���� */
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
 * @brief �ڱ��ָ��λ�ò���Ԫ��
 * @param p_sqList ��ṹ��ָ�룬ָ��Ҫ�����ı�
 * @param Order ����λ�õ�λ�򣨴�1��ʼ������
 * @param x Ҫ�����Ԫ��ֵ
 * @return ���������TRUE��ʾ�ɹ���FALSE��ʾʧ��
 */
my_bool insert_sqList_order(P_sqList p_sqList, int Order, int x)
{
    /* ���������Χ */
    int length = p_sqList->length + 1;
    if (length < 0 || length > p_sqList->size)
    {
        if (!expend_length_sqList(p_sqList))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* ����������һ  */
    p_sqList->length++;

    /* ת��λ��Ϊ���� */
    int index_end = LENGTH2INDEX(Order);
    int index_start = LENGTH2INDEX(p_sqList->length);

    /* ��ָ������֮���Ԫ�ض���ǰŲһλ  */
    for (int i = index_start; i >= index_end; i--)
    {
        p_sqList->head[i + 1] = p_sqList->head[i];
    }

    /* ָ���������и�ֵ����ԭ������ */
    p_sqList->head[index_end] = x;
}

/**
 * @brief ɾ����ṹ�������������
 * @param p_sqList ָ��Ҫɾ���ı�ṹ��ָ��
 * @return �޷���ֵ
 */
my_bool delete_sqList(P_sqList p_sqList)
{
    /* �ͷű�ͷռ�õ��ڴ� */
    free(p_sqList->head);
    /* �ͷű�ṹ����ռ�õ��ڴ� */
    free(p_sqList);
}

