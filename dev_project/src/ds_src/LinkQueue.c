#include "LinkQueue.h"
#include "tools.h"

/**
 * @brief ��ʼ��������
 * 
 * ����һ���µ������У������ڴ�ռ䲢��ʼ����ͷ�Ͷ�βָ��ΪNULL
 * 
 * @return �ɹ�ʱ����ָ���´��������е�ָ�룬ʧ��ʱ����NULL
 */
P_LinkQueue Init_LinkQueue()
{
    P_LinkQueue q = (P_LinkQueue)malloc(sizeof(LinkQueue));

    if (q == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        return NULL;
    }
    
    q->front = q->rear = NULL;

    return q;
}
/**
 * @brief �ж��������Ƿ�Ϊ��
 * 
 * @param q ָ�������е�ָ��
 * @return ����Ϊ��ʱ����TRUE�����򷵻�FALSE
 */
my_bool IsEmpty(P_LinkQueue q)
{
    return q->front == q->rear;
}

/**
 * @brief �������������Ԫ��
 * 
 * ��ָ��������������ӵ������е�β��������������п���ڵ���ֱ��ʹ�ã�
 * ����̬�����½ڵ�����չ���пռ䡣
 * 
 * @param q ָ�������е�ָ��
 * @param x Ҫ��ӵ���������
 * @return �����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
my_bool EnQueue(P_LinkQueue q, int x)
{
    /* ����п���Ԫ�� */
    if (q->rear != q->front)
    {
        q->rear->next->data = x;
        q->rear = q->rear->next;
        
        return TRUE;
    }
    /* ���򣬴���һ���½ڵ� */
    else if (q->rear->next == q->front)
    {

        P_LNode p = (P_LNode)malloc(sizeof(LNode));

        if (p == NULL)
        {
            printf("�ڴ����ʧ�ܣ�\n");
            return FALSE;
        }

        p->data = x;
        p->next = q->front;//ѭ������

        q->rear->next = p;
        q->rear = p;

        return TRUE;
    }

}


/**
 * @brief �Ӷ������߼�ɾ�������ض���Ԫ��
 * @param q ָ����е�ָ��
 * @return �������Ϊ�գ�����FALSE�����򷵻ض���Ԫ�ص�ֵ
 */
int DeQueue(P_LinkQueue q)
{
    // �������Ƿ�Ϊ��
    if (IsEmpty(q))
    {
        return FALSE;
    }

    // ��ȡ����Ԫ�ص�ֵ
    int x = q->front->data;
    // ������ָ���ƶ�����һ���ڵ�
    q->front = q->front->next;

    return x;
}


/**
 * @brief ��ӡ�������е�����Ԫ��
 * @param q ָ��Ҫ��ӡ�������е�ָ��
 */
void print_LinkQueue(P_LinkQueue q)
{
    P_LNode p = q->front;

    // ���������е�ÿ���ڵ㣬ֱ����β�ڵ�
    while (p != q->rear)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    // ��ӡ��β�ڵ�����ݲ�����
    printf("%d\n", p->data);
}

/**
 * ������ʽ���У��ͷŶ��������нڵ㼰���нṹ�屾����ڴ�
 * @param q ָ��Ҫ���ٵ���ʽ���е�ָ��
 */
void destroy_LinkQueue(P_LinkQueue q)
{
    P_LNode p = q->front->next;

    // ���������е�ÿ���ڵ㣬ֱ����β�ڵ�
    while (p != q->front)
    {
        P_LNode temp = p;
        p = p->next;
        free(temp);
    }

    // �ͷŶ�β�ڵ�
    free(q->front);

    // �ͷŶ��нṹ��
    free(q);
}

void test_LinkQueue()
{

    print_horizontal_line(20);
    printf("�����в��ԣ�\n");


    P_LinkQueue q = Init_LinkQueue();

    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    EnQueue(q, 4);
    EnQueue(q, 5);

    print_LinkQueue(q);

    printf("DeQueue: %d\n", DeQueue(q));
    printf("DeQueue: %d\n", DeQueue(q));

    print_LinkQueue(q);
}