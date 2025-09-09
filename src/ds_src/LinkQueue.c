#include "LinkQueue.h"
#include "tools.h"

//1表示未逻辑删除，0表示逻辑删除
static int flag = 1;


/**
 * @brief 初始化链队列
 * 
 * 创建一个新的链队列，分配内存空间并初始化队头和队尾指针为NULL
 * 
 * @return 成功时返回指向新创建链队列的指针，失败时返回NULL
 */
P_LinkQueue Init_LinkQueue()
{
    P_LinkQueue q = (P_LinkQueue)malloc(sizeof(LinkQueue));

    if (q == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    
    q->front = q->rear = NULL;

    return q;
}
/**
 * @brief 判断链队列是否为空
 * 
 * @param q 指向链队列的指针
 * @return 队列为空时返回TRUE，否则返回FALSE
 */
my_bool IsEmpty(P_LinkQueue q)
{
    return q->front == NULL && q->rear == NULL;
}

/**
 * @brief 向链队列中添加元素
 * 
 * 将指定的整型数据添加到链队列的尾部。如果队列中有空余节点则直接使用，
 * 否则动态分配新节点来扩展队列空间。
 * 
 * @param q 指向链队列的指针
 * @param x 要入队的整型数据
 * @return 操作成功返回TRUE，失败返回FALSE
 */
my_bool EnQueue(P_LinkQueue q, int x)
{
    
    // 如果队列为空
    if (IsEmpty(q))
    {
        P_LNode p = (P_LNode)malloc(sizeof(LNode));
        
        if (p == NULL)
        {
            printf("内存分配失败！\n");
            return FALSE;
        }
        
        p->data = x;
        p->next = p; // 循环队列

        q->front = q->rear = p;
        

    }
    
    /* 如果有空余元素 */
    else if (q->rear->next != q->front)
    {
        q->rear->next->data = x;
        q->rear = q->rear->next;
        
        return TRUE;
    }
    /* 否则，创建一个新节点(空队列，) */
    else
    {
        P_LNode p = (P_LNode)malloc(sizeof(LNode));
        
        if (p == NULL)
        {
            printf("内存分配失败！\n");
            return FALSE;
        }

        p->data = x;
        p->next = q->rear->next;
        
        q->rear->next = p;
        q->rear = p; 

        flag = 1;
        return TRUE;
    }

}


/**
 * @brief 从队列中逻辑删除并返回队首元素
 * @param q 指向队列的指针
 * @return 如果队列为空，返回FALSE；否则返回队首元素的值
 */
int DeQueue(P_LinkQueue q)
{
    int x;
    // 检查队列是否为空
    if (IsEmpty(q))
    {
        printf("队列为空！\n");
        return FALSE;
    }
    else if (q->front == q->rear && flag)
    {
        x = q->front->data;
        flag = 0;
    }
    else
    {
        // 获取队首元素的值
        x = q->front->data;
        // 将队首指针移动到下一个节点
        q->front = q->front->next;
    
    }

    return x;
}


/**
 * @brief 打印链队列中的所有元素
 * @param q 指向要打印的链队列的指针
 */
void print_LinkQueue(P_LinkQueue q)
{
    P_LNode p = q->front;

    // 遍历队列中的每个节点，直到队尾节点
    while (p != q->rear)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    // 打印队尾节点的数据并换行
    printf("%d\n", p->data);
}

/**
 * 销毁链式队列，释放队列中所有节点及队列结构体本身的内存
 * @param q 指向要销毁的链式队列的指针
 */
void destroy_LinkQueue(P_LinkQueue q)
{
    P_LNode p = q->front->next;

    // 遍历队列中的每个节点，直到队尾节点
    while (p != q->front)
    {
        P_LNode temp = p;
        p = p->next;
        free(temp);
    }

    // 释放队尾节点
    free(q->front);

    // 释放队列结构体
    free(q);
}

void test_LinkQueue()
{

    print_horizontal_line(20);
    printf("链队列测试：\n");


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
    
