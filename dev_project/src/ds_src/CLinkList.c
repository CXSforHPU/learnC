#include "CLinkList.h"

/**
 * ��ȡѭ������ĳ���
 * @param h ѭ�������ͷ�ڵ�
 * @return �����нڵ�ĸ���
 */
int get_length_CLinkList(CLinkList h) 
{
    int length = 0; 
    P_CNode p = h->next;
    while (p != h)
    {
        length++;
        p = p->next;
    }
    return length;
}

/**
 * ��ʼ��һ���յ�ѭ������
 * @return ָ���´�����ѭ������ͷ�ڵ��ָ�룬����ڴ����ʧ���򷵻�NULL
 */
CLinkList Init_CLinkList() 
{ 
    CLinkList head = (CLinkList)malloc(sizeof(CNode));
    // ��ͷ�ڵ��nextָ���Լ�������ѭ���ṹ
    head->next = head;
    // ͷ�ڵ�����������Ϊ-1����ʾ��Ч����
    head->data = -1;

    return head;
}

/**
 * ��ѭ������ͷ������һ���½ڵ�
 * @param h ѭ�������ͷ�ڵ�
 * @param x Ҫ���������ֵ
 * @return ����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool insert_head_CLinkList(CLinkList h, int x) 
{
    P_CNode q = (P_CNode)malloc(sizeof(CNode)); 
    if (q == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return FALSE;
    }
    
    q->data = x;
 
    // ���½ڵ���뵽ͷ�ڵ�֮��
    q->next = h->next;
    h->next = q;

    return TRUE;
}

/**
 * ��ѭ������β������һ���½ڵ�
 * @param h ѭ�������ͷ�ڵ�
 * @param x Ҫ���������ֵ
 * @return ����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool insert_tail_CLinkList(CLinkList h, int x) 
{
    P_CNode q = (P_CNode)malloc(sizeof(CNode));
    P_CNode p = h;
    
    if (q == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return FALSE;
    }
    
    // ��������������һ���ڵ�
    while (p->next != h)
    {
        p = p->next;
    }

    // ��β�������½ڵ�
    p->next = q;
    q->data = x;
    q->next = h;

    return TRUE;
}

/**
 * ɾ��ѭ�������е�һ��ֵΪx�Ľڵ�
 * @param h ѭ�������ͷ�ڵ�
 * @param x Ҫɾ���Ľڵ�ֵ
 * @return ɾ���ɹ�����TRUE��δ�ҵ���Ӧ�ڵ㷵��FALSE
 */
my_bool delete_CLinkList_value(CLinkList h, int x) 
{
    P_CNode p = h;
    // ��������Ѱ��Ҫɾ���Ľڵ�
    while (p->next != h)
    {
        if (p->next->data == x)
        {
            P_CNode q = p->next;
            p->next = q->next;
            free(q);
            return TRUE;
        }
        p = p->next;
    }

    return FALSE;
}

/**
 * ɾ��ѭ��������ָ��λ�õĽڵ�
 * @param h ѭ�������ͷ�ڵ�
 * @param length Ҫɾ���ڵ��λ�ã���1��ʼ������
 * @return ɾ���ɹ�����TRUE��λ����Ч����FALSE
 */
my_bool delete_CLinkList_length(CLinkList h, int length) 
{
    int max_length = get_length_CLinkList(h);
    if (length <= 0 || length > max_length)
    {
        printf("�����length����\n");
        return FALSE;
    }

    P_CNode p = h;
    while (p->next != h)
    {
        if (length == 1)
        {
            P_CNode q = p->next;
            p->next = q->next;
            free(q);
            return TRUE;
        }
        p = p->next;
        length--;
    } 
}

/**
 * ��ӡѭ�������е����нڵ�����
 * @param h ѭ�������ͷ�ڵ�
 */
void print_CLinkList(CLinkList h) 
{
    // �����Ա�̣����ͷ�ڵ��Ƿ�Ϊ��
    if (h == NULL) {
        return;
    }

    P_CNode p = h->next;
    if (p == h)
    {
        printf("ѭ������Ϊ��\n");
    }
    
    // ���Ӱ�ȫ�ԣ�ȷ��������Ϊ����ṹ�����������ѭ��
    while (p != h && p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * ��ѭ���������ѡ������
 * @param h ѭ�������ͷ�ڵ�ָ��
 */
void select_sort_CLinkList(CLinkList h)
{
    // �������Ϊ�ջ�ֻ��һ���ڵ㣬����������
    if (h == NULL || h->next == NULL)
    {
        return;
    }

    P_CNode i = h->next;

    // ���ѭ��������ÿ��δ����Ľڵ�
    while(i != h)
    {
        P_CNode min_node = i;  // ���赱ǰλ��Ϊ��Сֵ�ڵ�
        P_CNode j = i->next;   // ����һ���ڵ㿪ʼ�Ƚ�
        
        // �ڲ�ѭ������ʣ��δ���򲿷���Ѱ����Сֵ�ڵ�
        while(j != h)
        {
            if (j->data < min_node->data)
            {
                min_node = j;  // ������Сֵ�ڵ�
            }
            j = j->next;
        }

        // ����ҵ���С�Ľڵ㣬�򽻻�����
        if (min_node != i)
        {
            swap_int(&i->data, &min_node->data);
        }
        
        i = i->next;  // �ƶ�����һ��δ����ڵ�
    }

}



