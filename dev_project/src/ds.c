#include "ds.h"
#include "tools.h"

#define MAX_TABLE_SIZE 10
#define TABLE_EXPEND_TIMES 2
/* ˳��� */

/**
 * @brief ��չ���ĳ��ȣ���������������TABLE_EXPEND_TIMES��
 * @param p_sqList - ָ����ṹ���ָ��
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

    /* ���±��Ĵ�С��Ϣ */

    p_sqList->head = new_head;
    p_sqList->size = new_size;

    return TRUE;
}

/**
 * @brief ��ʼ��˳���
 * @return ����ָ���´���˳�����ָ��
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
 * @brief ��ӡ��������
 * @param p_sqList ָ�����ṹ���ָ�룬����Ҫ��ӡ������
 *                     - head: ָ�����������ָ��
 *                     - length: ������Ԫ�صĸ���
 * @return �޷���ֵ
 */
void Print_sqList(P_sqList p_sqList)
{
    /* ���������е�����Ԫ�ز���ӡ */
    for (int i = 0; i < p_sqList->length; i++)
    {
        printf("%d ", p_sqList->head[i]);
    }
    /* ��ӡ��ɺ��� */
    printf("\n");
}

/**
 * @brief ���������Ԫ��
 * @param p_sqList ���ṹ��ָ�룬��������ͷָ�롢���Ⱥ�������Ϣ
 * @param x Ҫ���ӵ����е�����Ԫ��
 * @return ���ӳɹ�����TRUE��ʧ�ܷ���FALSE
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

    /* ����Ԫ�����ӵ�����ĩβ�����³��� */
    p_sqList->head[p_sqList->length] = x;
    p_sqList->length++;
    return TRUE;
}

/**
 * @brief �ӱ���ɾ��ָ��λ�õ�Ԫ��
 * @param p_sqList ָ����ṹ��ָ��
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
 * @brief �ڱ���ָ��λ�ò���Ԫ��
 * @param p_sqList ���ṹ��ָ�룬ָ��Ҫ�����ı�
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
 * @brief ɾ�����ṹ�������������
 * @param p_sqList ָ��Ҫɾ���ı��ṹ��ָ��
 * @return �޷���ֵ
 */
my_bool delete_sqList(P_sqList p_sqList)
{
    /* �ͷű�ͷռ�õ��ڴ� */
    free(p_sqList->head);
    /* �ͷű��ṹ����ռ�õ��ڴ� */
    free(p_sqList);
}

/* ���� */

/**
 * @brief ��ʼ��һ������
 * @return ָ���´�������ͷ�ڵ��ָ�룬�������ʧ���򷵻�NULL
 */
LinkList init_list()
{
    /* �����ڴ��Դ����µ�ͷ�ڵ� */
    LinkList head = (LinkList)malloc(sizeof(LNode));

    /* ����ڴ�����Ƿ�ɹ� */
    if (head == NULL)
    {
        printf("creat fail!\n");
        return NULL;
    }

    /* ��ʼ��ͷ�ڵ�����ݺ�ָ�� */
    head->data = 0;
    head->next = NULL;

    return head;
}

/**
 * @brief �ڴ�ͷ���ĵ�����ͷ�������½��
 * @param h ������ͷָ��
 * @param x Ҫ���������ֵ
 * @return �����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool head_insect(LinkList h, int x)
{
    /* �����½�� */
    P_LNode q = (P_LNode)malloc(sizeof(LNode));

    if (q == NULL)
    {
        printf("creat fail!\n");
        return FALSE;
    }
    /* ��ֵ */
    q->data = x;

    /* ͷ�巨������ */
    q->next = h->next;
    h->next = q;

    return TRUE;
}

/**
 * @brief ��ӡ�����е�����Ԫ��
 * @param h ����ͷ�ڵ��ָ��
 * @return �޷���ֵ
 */
void print_list(LinkList h)
{
    /* �����������ӵ�һ����Ч�ڵ㿪ʼ */
    P_LNode p = h->next;

    /* ���δ�ӡÿ���ڵ�������� */
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    /* ��ӡ���з���ʹ��������� */
    printf("\n");
}

/**
 * @brief ���������ĳ���
 * @param h ����ͷָ��
 * @return �����нڵ�ĸ���
 */
int get_length(LinkList h)
{
    int length = 0;
    P_LNode p = h;

    /* ��������ֱ��ĩβ��ͳ�ƽڵ����� */
    while (p->next != NULL)
    {
        length++;
        p = p->next;
    }

    return length;
}
/**
 * @brief ������β�������½ڵ�
 * @param h ����ͷָ��
 * @param data Ҫ���������
 * @return ����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool tail_insect(LinkList h, int data)
{
    P_LNode q = (P_LNode)malloc(sizeof(LNode));
    P_LNode p = h;
    if (q == NULL)
    {
        printf("creat fail!\n");
        return FALSE;
    }

    /* ��ֵ */
    q->data = data;
    q->next = NULL;

    /* �ҵ����һ���ڵ� */
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = q;

    return TRUE;
}

/**
 * @brief ����ָ�����Ȳ��������еĽڵ�ָ��
 * @param h ������ͷָ��
 * @param length Ҫ���ҵ�λ�ó��ȣ���1��ʼ������
 * @return ���ص�length���ڵ��ָ�룬���������Χ�򷵻�NULL
 */
P_LNode find_P_LNode_length(LinkList h, int length)
{
    int max_length = get_length(h);

    /* ��鳤���Ƿ�����Ч��Χ�� */
    if (length < 0 || length > max_length)
    {
        return NULL;
    }
    else if (length == 0) /*����ͷָ��*/
    {
        return h;
    }

    int i = 1;
    P_LNode p = h;

    /* ��������ֱ���ҵ�ָ��λ�� */
    while (p->next != NULL && i <= length)
    {
        p = p->next;
        i++;
    }

    return p;
}

/**
 * @brief �������в��Ҿ���ָ��ֵ�Ľڵ�
 * @param h ������ͷָ��
 * @param value Ҫ���ҵ�ֵ
 * @return �ҵ��Ľڵ�ָ�룬���δ�ҵ��򷵻�NULL
 */
P_LNode find_P_LNode_value(LinkList h, int value)
{
    P_LNode p = h;

    /* ������������Ŀ��ֵ */
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
 * @brief ɾ��������ָ��λ�õĽڵ�
 * @param h ����ͷָ��
 * @param length Ҫɾ���ڵ��λ�ã���1��ʼ������
 * @return ɾ���ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool delete_P_LNode_length(LinkList h, int length)
{
    P_LNode q = NULL;

    /* ����Ҫɾ���ڵ��ǰһ���ڵ� */
    P_LNode p = find_P_LNode_length(h, length - 1);

    if (p == NULL)
    {
        return FALSE;
    }
    /* ɾ���ڵ� */
    q = p->next;
    p->next = q->next;
    free(q);

    return TRUE;
}

/**
 * @brief ��������ɾ��ָ��ֵ�Ľڵ�
 * @param h ����ͷ�ڵ�ָ��
 * @param value Ҫɾ���Ľڵ�ֵ
 * @return TRUE��ʾɾ���ɹ���FALSE��ʾδ�ҵ���ֵ
 */
my_bool delete_P_LNode_value(LinkList h, int value)
{
    P_LNode q = NULL;
    P_LNode p = h;

    /* ������������Ҫɾ���Ľڵ� */
    while (p->next != NULL)
    {
        /* �����һ���ڵ����һ���ڵ��Ƿ�ΪĿ��ֵ */
        if (p->next->data == value)
        {
            /* �ҵ�Ŀ��ڵ㣬ִ��ɾ������ */
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
 * @brief ��������ָ��λ�ò����½ڵ�
 * @param h ����ͷָ��
 * @param length ����λ�ã���1��ʼ������
 * @param data Ҫ���������
 * @return ����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool insert_P_LNode_length(LinkList h, int length, int data)
{
    /* ���Ҳ���λ�õ�ǰһ���ڵ�,�Ҳ���˵������length������ */
    P_LNode p = find_P_LNode_length(h, length - 1);
    if (p == NULL)
    {
        return FALSE;
    }

    /* �����½ڵ��ڴ� */
    P_LNode q = (P_LNode)malloc(sizeof(LNode));

    if (q == NULL)
    {
        return FALSE;
    }

    /* ��ֵ */
    q->data = data;

    /* ִ�в������ */
    q->next = p->next; /* ��һ���ڵ���� NULL */
    p->next = q;

    return TRUE;
}

/**
 * @brief �ͷ������е����нڵ�
 * @param h ����ͷָ��
 * @return TRUE - �ɹ��ͷ����нڵ�
 */
my_bool free_nodes(LinkList h)
{
    P_LNode p = h->next;

    /* ѭ���ͷŽڵ� */
    while (p != NULL)
    {
        P_LNode q = p->next;
        free(p);
        p = q;
    }

    /* ��Ҫ����NULL */
    h->next = NULL;
    return TRUE;
}

/**
 * @brief ��������
 * @param h ����ͷָ��
 * @return ����TRUE��ʾ���ٳɹ�
 */
my_bool destroy_list(LinkList h)
{
    /* �ͷ����нڵ��ڴ� */
    free_nodes(h);
    /* �ͷ�ͷָ���ڴ� */
    free(h);
    return TRUE;
}