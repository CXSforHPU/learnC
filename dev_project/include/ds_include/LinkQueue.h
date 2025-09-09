#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

#include "LinkList.h"


typedef struct LinkQueue 
{
    P_LNode front, rear; 
} LinkQueue,*P_LinkQueue;

// Ìí¼Óº¯ÊýÉùÃ÷
P_LinkQueue Init_LinkQueue();
my_bool IsEmpty(P_LinkQueue q);
my_bool EnQueue(P_LinkQueue q, int x);
int DeQueue(P_LinkQueue q);
void print_LinkQueue(P_LinkQueue q);
void destroy_LinkQueue(P_LinkQueue q);
void test_LinkQueue();

#endif //_LINKQUEUE_H