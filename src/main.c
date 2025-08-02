#include "tools.h"
int main()
{
#ifdef _WIN32
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif

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

#ifdef FAHRENHEIT_TO_CELSIUS_EXAMPLE
    // 测试华氏温度转摄氏温度
    printf("fahrenheit_to_celsius(100) = %f\n", fahrenheit_to_celsius(100.0f));
#endif

#ifdef TEST_ESCAPE_CHARACTERS_EXAMPLE
    // 测试转义字符
    test_escape_characters();
    printf("%d\n", strlen("c:\test\32\test.c")); // 任何转义字符都是一个字符 输出13
#endif

#ifdef TEST_UPPER_TO_LOWER_EXAMPLE
    // 测试大小写转换
    char ch1 = 'a';
    char ch2 = 'A';
    test_upper_to_lower(&ch1);
    test_upper_to_lower(&ch2);
    printf("to_lower('a') = %c\n", ch1);
    printf("to_lower('A') = %c\n", ch2);
#endif

#ifdef TRIANGLE_AREA_EXAMPLE
    // 测试三角形面积
    printf("三角形面积 = %f\n", triangle_area(3.0f, 4.0f, 5.0f));
#endif
    system("pause");

    return 0;
}