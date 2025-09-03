#include "LinkList.h"

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
 * @param h �����ͷָ��
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
    /* ���������ӵ�һ����Ч�ڵ㿪ʼ */
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
 * @brief ��������ĳ���
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
 * @param h �����ͷָ��
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
 * @param h �����ͷָ��
 * @param value Ҫ���ҵ�ֵ
 * @return �ҵ��Ľڵ�ָ�룬���δ�ҵ��򷵻�NULL
 */
P_LNode find_P_LNode_value(LinkList h, int value)
{
    P_LNode p = h;

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