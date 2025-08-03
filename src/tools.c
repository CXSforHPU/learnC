#include "tools.h"

#ifdef SUM_EXAMPLE
/*
@brief 求和
@param int num1 数字1
@param int num2 数字2
@return 返回和
*/
int sum(int num1, int num2)
{
    int sum_number = num1 + num2;

    return sum_number;
}
#endif

#ifdef COMPARE_EXAMPLE
/*
@brief 获取两个数字中的最大值
@param int num1 数字1
@param int num2 数字2
@return 返回两个数字中的最大值
*/
int compare(int num1, int num2)
{
    return num1 >= num2 ? num1 : num2;
}
#endif

#ifdef USE_SCANF_EXAMPLE
/*
@brief 检测输入以及比较大小后输出
*/
void use_scanf()
{
    int a = 0;
    int b = 0;
    int max = 0;
    scanf("%d %d", &a, &b);
    printf("a=%d, b=%d\n", a, b);

    max = compare(a, b);
    printf("max=%d\n", max);
}
#endif

#ifdef FACTORIAL_EXAMPLE
/*
@brief 阶乘函数
@param int num
@return 阶乘结果
*/
int factorial(int num)
{
    int result = 1;

    if (num <= 0)
    {
        return -1;
    }

    for (int i = num; i > 0; i--)
    {
        result *= i;
    }

    return result;
}
#endif

#ifdef GET_VALUE_EXAMPLE
/*
@brief 获取函数值
1-1/2+1/3 + 1/(n+1)*(-1)^n
@param n 数列的项数
@return 数列求和
*/
double get_value(int n)
{
    int sign = 1.0;
    double result = 0.0;

    if (n <= 0)
    {
        return -1.0;
    }

    for (double i = 1; i <= n; i++)
    {
        result += (1.0 / i) * sign;
        sign *= -1;
    }
    return result;
}
#endif

#ifdef IS_PRIME_EXAMPLE
/*
@brief 判断是否是素数
@param int num 素数
@return 是不是素数
*/
my_bool is_prime(int num)
{
    int target = (int)sqrt((double)num);
    if (num <= 1)
    {
        return FALSE;
    }

    for (int i = 2; i <= target; i++)
    {
        if (num % i == 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}
#endif

#ifdef FAHRENHEIT_TO_CELSIUS_EXAMPLE
/*
@brief 华氏温度转换摄氏温度
@param float fahrenheit 华氏温度
@reture 摄氏温度
*/
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}
#endif

#ifdef TEST_ESCAPE_CHARACTERS_EXAMPLE
/*
@brief 测试转义字符的使用
*/
void test_escape_characters()
{
    // 测试换行符 \n
    printf("这是第一行\n这是第二行\n");

    // 测试制表符 \t
    printf("姓名\t年龄\t城市\n");
    printf("张三\t25\t北京\n");

    // 测试反斜杠本身
    printf("路径: C:\\Program Files\\MyApp\\\n");

    // 测试双引号 \"
    printf("他说: \"Hello World\"\n");

    // 测试单引号 \'
    printf("字符 \'A\' 的ASCII码是 %d\n", 'A');

    // 测试回车和换行 \r\n (Windows风格)
    printf("第一行\r\n第二行\r\n");

    // 测试响铃字符 \a
    printf("响铃测试: \a请看这里!\n");

    // 测试退格字符 \b
    printf("测试退格: ABCD\b\b\b\b1234\n");

    // 测试八进制转义字符
    printf("八进制101表示字符: \101\n");

    // 测试十六进制转义字符
    printf("十六进制41表示字符: \x41\n");
}
#endif

#ifdef TEST_UPPER_TO_LOWER_EXAMPLE
/*
@brief 大写字母转小写字母 仅仅针对字符 非字符串
*/
void test_upper_to_lower(char *ch)
{

    if (*ch >= 65 && *ch <= 90) // A - 65； Z - 90
    {
        *ch = *ch + 32;
    }
}
#endif

#ifdef TRIANGLE_AREA_EXAMPLE
/*
@breif 求三角形面积
@param float a, float b, float c 三角形三条边的长度
@return 三角形面积
*/
float triangle_area(float a, float b, float c)
{
    // 检查边长是否为正数
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("错误：三角形的边长必须为正数\n");
        return -1.0f;
    }
    
    // 检查是否满足三角形条件（任意两边之和大于第三边）
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        printf("错误：输入的三边长度不能构成三角形\n");
        return -1.0f;
    }
    
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
#endif

#ifdef TEST_INPUT_OUTPUT_EXAMPLE
/*
@breif 测试输入输出
*/
void test_input_output()
{
    ;
}
#endif