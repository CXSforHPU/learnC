#include "ds.h"
#include "tools.h"

#define MAX_TABLE_SIZE 10
#define TABLE_EXPEND_TIMES 2
/* ˳��� */

/**
 * @brief ��չ��ĳ��ȣ��������������TABLE_EXPEND_TIMES��
 * @param table_pointer - ָ���ṹ���ָ��
 * @return ��չ�ɹ�����TRUE��ʧ�ܷ���FALSE
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

    /* ���·����ڴ�ռ䣬��������չTABLE_EXPEND_TIMES�� */
    int *new_head = (int *)realloc(table_pointer->head, new_size * sizeof(int));

    if (new_head == NULL)
    {
        printf("realloc fail!\n");
        return FALSE;
    }

    /* ���·�����ڴ�ռ��ʼ��Ϊ0 */
    memset(new_head + old_size, 0, (new_size - old_size) * sizeof(int));

    /* ���±�Ĵ�С��Ϣ */

    table_pointer->head = new_head;
    table_pointer->size = new_size;

    return TRUE;
}

/**
 * @brief ��ʼ��˳���
 * @return ����ָ���´���˳����ָ��
 */
Table_pointer InitTable()
{
    /* �����ڴ��Դ����µ�˳���  */
    Table_pointer table_point = (Table_pointer)malloc(sizeof(Table));

    table_point->head = (int *)malloc(MAX_TABLE_SIZE * sizeof(int));
    table_point->length = 0;
    table_point->size = MAX_TABLE_SIZE;

    /* ��ʼ������Ԫ��Ϊ0 */
    memset(table_point->head, 0, sizeof(table_point->head));
}

/**
 * @brief ��ӡ�������
 * @param table_pointer ָ����ṹ���ָ�룬����Ҫ��ӡ������
 *                     - head: ָ�����������ָ��
 *                     - length: �����Ԫ�صĸ���
 * @return �޷���ֵ
 */
void PrintTable(Table_pointer table_pointer)
{
    /* ��������е�����Ԫ�ز���ӡ */
    for (int i = 0; i < table_pointer->length; i++)
    {
        printf("%d ", table_pointer->head[i]);
    }
    /* ��ӡ��ɺ��� */
    printf("\n");
}

/**
 * @brief ��������Ԫ��
 * @param table_pointer ��ṹ��ָ�룬�������ͷָ�롢���Ⱥ�������Ϣ
 * @param x Ҫ��ӵ����е�����Ԫ��
 * @return ��ӳɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool add_table(Table_pointer table_pointer, int x)
{
    /* �����Ƿ���������������������� */
    if (table_pointer->length == table_pointer->size)
    {
        /* ����ʧ��ʱ���������Ϣ������FALSE */
        if (!expend_length_table(table_pointer))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* ����Ԫ����ӵ����ĩβ�����³��� */
    table_pointer->head[table_pointer->length] = x;
    table_pointer->length++;
    return TRUE;
}

/**
 * @brief �ӱ���ɾ��ָ��λ�õ�Ԫ��
 * @param table_pointer ָ���ṹ��ָ��
 * @param Order Ҫɾ��Ԫ�ص�λ������
 * @return �ɹ�ɾ������TRUE������Խ�緵��FALSE
 */
my_bool remove_Order(Table_pointer table_pointer, int Order)
{
    /* ���������Χ */
    if (Order < 0 || Order >= table_pointer->length)
    {
        return FALSE;
    }

    /* ɾ��Ԫ��,������ǰ���� */
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
 * @brief �ڱ��ָ��λ�ò���Ԫ��
 * @param table_pointer ��ṹ��ָ�룬ָ��Ҫ�����ı�
 * @param Order ����λ�õ�λ�򣨴�1��ʼ������
 * @param x Ҫ�����Ԫ��ֵ
 * @return ���������TRUE��ʾ�ɹ���FALSE��ʾʧ��
 */
my_bool insert_table_order(Table_pointer table_pointer, int Order, int x)
{
    /* ���������Χ */
    int length = table_pointer->length + 1;
    if (length < 0 || length > table_pointer->size)
    {
        if (!expend_length_table(table_pointer))
        {
            printf("realloc fail!\n");
            return FALSE;
        }
    }

    /* ����������һ  */
    table_pointer->length++;

    /* ת��λ��Ϊ���� */
    int index_end = LENGTH2INDEX(Order);
    int index_start = LENGTH2INDEX(table_pointer->length);

    /* ��ָ������֮���Ԫ�ض���ǰŲһλ  */
    for (int i = index_start; i >= index_end; i--)
    {
        table_pointer->head[i + 1] = table_pointer->head[i];
    }

    /* ָ���������и�ֵ����ԭ������ */
    table_pointer->head[index_end] = x;
}

/**
 * @brief ɾ����ṹ�������������
 * @param table_pointer ָ��Ҫɾ���ı�ṹ��ָ��
 * @return �޷���ֵ
 */
my_bool delete_table(Table_pointer table_pointer)
{
    /* �ͷű�ͷռ�õ��ڴ� */
    free(table_pointer->head);
    /* �ͷű�ṹ����ռ�õ��ڴ� */
    free(table_pointer);
}

/* ���� */

/**
 * @brief ��ʼ��һ������
 * @return ָ���´�������ͷ�ڵ��ָ�룬�������ʧ���򷵻�NULL
 */
head_pointer init_list()
{
    /* �����ڴ��Դ����µ�ͷ�ڵ� */
    head_pointer head = (head_pointer)malloc(sizeof(node));

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
 * @param h �����ͷָ��
 * @param x Ҫ���������ֵ
 * @return �����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool head_insect(head_pointer h, int x)
{
    /* �����½�� */
    node_pointer q = (node_pointer)malloc(sizeof(node));

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
void print_list(head_pointer h)
{
    /* ���������ӵ�һ����Ч�ڵ㿪ʼ */
    node_pointer p = h->next;

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
 * @brief ��������ĳ���
 * @param h ����ͷָ��
 * @return �����нڵ�ĸ���
 */
int get_length(head_pointer h)
{
    int length = 0;
    node_pointer p = h;

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
my_bool tail_insect(head_pointer h, int data)
{
    node_pointer q = (node_pointer)malloc(sizeof(node));
    node_pointer p = h;
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
 * @param h �����ͷָ��
 * @param length Ҫ���ҵ�λ�ó��ȣ���1��ʼ������
 * @return ���ص�length���ڵ��ָ�룬���������Χ�򷵻�NULL
 */
node_pointer find_node_pointer_length(head_pointer h, int length)
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
    node_pointer p = h;

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
 * @param h �����ͷָ��
 * @param value Ҫ���ҵ�ֵ
 * @return �ҵ��Ľڵ�ָ�룬���δ�ҵ��򷵻�NULL
 */
node_pointer find_node_pointer_value(head_pointer h, int value)
{
    node_pointer p = h;

    /* �����������Ŀ��ֵ */
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
my_bool delete_node_pointer_length(head_pointer h, int length)
{
    node_pointer q = NULL;

    /* ����Ҫɾ���ڵ��ǰһ���ڵ� */
    node_pointer p = find_node_pointer_length(h, length - 1);

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
my_bool delete_node_pointer_value(head_pointer h, int value)
{
    node_pointer q = NULL;
    node_pointer p = h;

    /* �����������Ҫɾ���Ľڵ� */
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
 * @brief �������ָ��λ�ò����½ڵ�
 * @param h ����ͷָ��
 * @param length ����λ�ã���1��ʼ������
 * @param data Ҫ���������
 * @return ����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool insert_node_pointer_length(head_pointer h, int length, int data)
{
    /* ���Ҳ���λ�õ�ǰһ���ڵ�,�Ҳ���˵������length������ */
    node_pointer p = find_node_pointer_length(h, length - 1);
    if (p == NULL)
    {
        return FALSE;
    }

    /* �����½ڵ��ڴ� */
    node_pointer q = (node_pointer)malloc(sizeof(node));

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
my_bool free_nodes(head_pointer h)
{
    node_pointer p = h->next;

    /* ѭ���ͷŽڵ� */
    while (p != NULL)
    {
        node_pointer q = p->next;
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
my_bool destroy_list(head_pointer h)
{
    /* �ͷ����нڵ��ڴ� */
    free_nodes(h);
    /* �ͷ�ͷָ���ڴ� */
    free(h);
    return TRUE;
}