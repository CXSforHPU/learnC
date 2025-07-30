#include "tools.h"

/*
@brief 求和
@param num1 数字1
@param num2 数字2
@return 返回和
*/
int sum(int num1, int num2)
{
    int sum_number = num1 + num2;

    return sum_number;
}

/*
@brief 获取两个数字中的最大值
@param num1 数字1
@param num2 数字2
@return 返回两个数字中的最大值
*/
int compare(int num1, int num2)
{
    return num1 >= num2 ? num1 :num2;
}

/*
@brief 检测输入以及比较大小后输出
*/
void use_scanf()
{
    int a = 0;
    int b = 0;
    int max = 0;
    scanf("%d %d", &a, &b);
    printf("a=%d, b=%d\n",a,b);
    
    max = compare(a,b);
    printf("max=%d\n",max);
}