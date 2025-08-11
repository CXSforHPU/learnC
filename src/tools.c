#include "tools.h"

#if defined(USE_STDARG_H) && defined(USE_MATH_H) && defined(USE_MY_TYPE_H)
static my_bool is_fp_zero(double number)
{   
    if (fabs(number) < EPSILON)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
static my_bool is_int_zero(int number)
{
    if (number == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*
主要问题是C语言中可变参数传递时，
float 类型会被自动提升为 double 类型，
所以即使声明为 float，实际传入的也是 double。
*/
my_bool is_zero(math_type number_type,...)
{
    va_list args;
    my_bool result = FALSE;
    va_start(args, number_type);

    switch (number_type)
    {
    case Int:
        result = is_int_zero(va_arg(args, int));
        break;
    case Double:
        result = is_fp_zero(va_arg(args, double));
        break;
    default:
        return FALSE;
    }

     va_end(args);

     return result;
}

#endif

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
    char name[10]= "\0";
    char description[50] = "\0";
    int age = 0;
    char ch = 0;
    float height = 0.0f;

    // scanf("%d%c%f", &age, &ch, &height);
    // printf("%d %c %f\n", age,ch,height);
    // scanf("%s %s", name,description);
    // printf("请输入您的姓名：%s\n描述%s\n",name,description);

    // fgets(description, sizeof(description), stdin);
    // fputs(description, stdout);

    // printf("%7d\n",age);

    char ch1 = getchar();  // int

    test_upper_to_lower(&ch1);

    printf(ch1);

}
#endif


#ifdef TEST_SOLVE_QUADRATIC_EQUATION_EXAMPLE
/*
@breif :一元二次方程求解
        a*x^2+bx+c=0
@param :double a x^2
@param :double b x
@param :double c 常数项
@return :两根值
*/
double* solve_quadratic_equation(double a, double b, double c) 
{
    // 处理a=0的情况（线性方程）
    if (is_zero(Double,a)) {
        printf("系数a不能为0，这不是一个二次方程\n");
        return NULL;
    }
    
    // 动态分配内存以避免返回局部变量地址
    double* result = (double*)malloc(2 * sizeof(double));
    if (result == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    
    memset(result, 0, 2 * sizeof(double));

    double disc = pow(b,2.0)-4*a*c;
    double p = 0.0;
    double q = 0.0;
    
    if (disc >= 0)
    {   
        p = sqrt(disc)/(2*a);
        q = -b/(2*a);
        result[0] = q+p;
        result[1] = q-p;
    }
    else
    {
        printf("No real root\n");
    }

    return result;
}

#endif

#ifdef TEST_SWAP_INT_EXAMPLE
/*
@breif 交换两个数值
@param num1, num2
@return void
*/
void swap_int(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

#endif

#ifdef USE_SWITCH_CASE_EXAMPLE
/*
@breif 使用switch case
@param num
@return void
*/

void use_switch_case(int num)
{
    switch (num)
    {
    case 1:
        printf("one\n");
        break;
    case 2:
        printf("two\n");
        break;
    case 3:
        printf("three\n");
        break;
    default:
        printf("Invalid number\n");
        break;
    }
}
#endif

#ifdef IS_LEAP_YEAR_EXAMPLE
/*
@breif 判断闰年
    普通年能被4整除且不能被100整除的为闰年。否则为平年。（如2004年就是闰年，1900年不是闰年）
    世纪年能被400整除的是闰年。否则为平年。（如2000年是闰年，1900年不是闰年）
@param int year
@return my_bool
*/
my_bool is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

#endif

#ifdef FIBONACCI_SEQUENCE
/*
@brief 测试费波纳茨数列
@param int n
@return int* fibonacci_sequence
*/
int* get_fibonacci_sequence(int n)
{
    // 申请内存
    int* fibonacci_sequence = (int*) malloc((n+1) * sizeof(int));
    if (fibonacci_sequence == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // 初始化 为0
    memset(fibonacci_sequence, 0, (n+1) * sizeof(int));

    //存储信息
    fibonacci_sequence[0] = n; //存储总数信息

    //计算数列
    if (n == 1)
    {
        fibonacci_sequence[1] = 1;
    }
    else if (n == 2)
    {
        fibonacci_sequence[2] = 2;
    }
    else
    {
        fibonacci_sequence[1] = 1;
        fibonacci_sequence[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            fibonacci_sequence[i] = fibonacci_sequence[i-1] + fibonacci_sequence[i-2];
        }
    }
    return fibonacci_sequence;
}

void print_fibonacci_sequence(int* fibonacci_sequence)
{
    if (fibonacci_sequence == NULL)
    {
        return;
    }
    
    int num = fibonacci_sequence[0];

    printf("the fibonacci sequence are: \n");

    for (int i = 1; i <= num; i++)
    {
        printf("序号%-5d:\t%10d\n", i,fibonacci_sequence[i]);
    }
    
    printf("\n");
}
int get_fibonacci_sequence_num(int* fibonacci_sequence)
{
    if (fibonacci_sequence == NULL)
    {
        return FALSE;
    }

    return fibonacci_sequence[0];
    
}

#endif