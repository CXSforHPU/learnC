#include "ds.h"
#include "config.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* test ds */

void TestDs()
{

#ifdef LEARN_LINK
	/* LinkNode */ 
	HeadPointer head = InitLinkHead();
	LinkHeadInsert(head,5);
	LinkHeadInsert(head,10);
	LinkHeadInsert(head,20);
	
	PrintLink(head);
#endif

}




int main(int argc, char *argv[]) {
	
	TestDs();
	
	system("pause");
	
	return 0;
}
