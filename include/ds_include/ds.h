#ifndef __DS_H__
#define __DS_H__

#include "tools.h"

#ifndef WEAK
#define WEAK __attribute__((weak)) 
#endif

WEAK typedef int NAME;


WEAK typedef struct DATA
{
    NAME name;
    int data;
}DATA,*pDATA;

/* 导入数据结构头文件 */
#include "list.h"
#include "table.h"


#endif