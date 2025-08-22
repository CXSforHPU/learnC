#ifndef __DS_H
#define __DS_H

#include "stdio.h"
#include "stdlib.h"

/* Á´±í */

typedef struct node
{
	int data;
	struct node* next;
}node,*NodePointer;

typedef NodePointer HeadPointer;


HeadPointer InitLinkHead();
void LinkHeadInsert(HeadPointer Head,int x);
void PrintLink(HeadPointer Head);


#endif
