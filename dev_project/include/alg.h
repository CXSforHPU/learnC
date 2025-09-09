#ifndef __ALG_H__
#define __ALG_H__ 
#include "tools.h"
#include "ds.h"


#ifdef TEST_LEFT_MOVE

void left_move(int *array, int length, int n);
int get_two_arr_middle_number(int *arr1, int *arr2, int length1, int length2);
#endif

void concat_clinklist(CLinkList h1, CLinkList h2);
void test_concat_clinklist();
void del_clinklist_ascending_order(CLinkList h);
void test_del_clinklist_ascending_order();
size_t transform_ten2two(int num);
void test_transform_ten2two();

#endif //__ALG_H__