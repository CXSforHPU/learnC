#include "tools.h"
#include "config.h"
int main()
{

    // 输出
    printf("hello world\n");

#ifdef SUM_EXAMPLE
    // 求和
    printf("sum(10,20) = %d\n", sum(10, 20));
#endif

#ifdef COMPARE_EXAMPLE
    // 比较
    printf("compare(10,20) = %d\n", compare(10, 20));
#endif

#ifdef USE_SCANF_EXAMPLE
    // 输入输出
    use_scanf();
#endif

#ifdef FACTORIAL_EXAMPLE
    // 测试阶乘
    printf("factorial(5) = %d\n", factorial(5));
#endif

#ifdef GET_VALUE_EXAMPLE
    // 获取值
    printf("get_value(100) = %f\n", get_value(100));
#endif

#ifdef IS_PRIME_EXAMPLE
    // 测试素数
    printf("is_prime(13) = %d\n", is_prime(13));
#endif

    return 0;
}