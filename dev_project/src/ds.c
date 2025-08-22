#include "ds.h"

 HeadPointer InitLinkHead()
 {
 	HeadPointer Head = (HeadPointer) malloc(sizeof(node));
 	
 	if(Head == NULL)
 	{
 		printf("creat falie\n");
 		return NULL;
	}
	
	Head->data = 0;
	Head->next = NULL;

}

void LinkHeadInsert(HeadPointer Head,int x)
{
	NodePointer p = (NodePointer)malloc(sizeof(node));
	
	if(p == NULL)
	{
		printf("creat falie\n");
 		return ;
	}
	
	p->data = x;
	p->next = Head->next;
	Head->next = p;
}


void PrintLink(HeadPointer Head)
{
	NodePointer p = Head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}









