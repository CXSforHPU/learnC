#include "stdio.h"
#include "tools.h"
int main()
{
    //输出
    printf("hello world\n");
    
    //求和
    printf("sum(10,20) = %d\n", sum(10,20));
    
    //比较
    printf("compare(10,20) = %d\n", compare(10,20));
    
    //输入输出
    use_scanf();

    return 0;
}