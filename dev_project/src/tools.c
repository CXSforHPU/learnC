#include "tools.h"


void print_horizontal_line(int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("-");
    }
    printf("\n");
}

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
my_bool is_zero(math_type number_type, ...)
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

#ifdef SORT_FUCTION

void print_int_array(int *array, int length)
{
    int index = LENGTH2INDEX(length);
    for (int i = 0; i <= index; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*
@brief 冒泡排序
    时间复杂度 O(n^2)
    稳定
    空间复杂度 O(1)
@param int* array 数组
@param int length 位序
    与索引不同
@return 无
*/
void bubble_sort(int *array, int length)
{
    int max_index = LENGTH2INDEX(length);
    /* 确定排序趟数 max_index - 1 */
    for (int i = max_index; i > 0; i--)
    {
        /* 确定比较的元素个数 其中 i是此趟排序确定的 索引 */
        for (int j = 1; j <= i; j++)
        {
            array[j] > array[j - 1] ?: swap_int(&array[j], &array[j - 1]);
        }
    }
}

/*
@brief 选择排序
    算法特点
    时间复杂度：O(n) - 无论最好、最坏还是平均情况
    空间复杂度：O(1) - 原地排序算法
    稳定性：不稳定排序
    比较次数：固定为 n(n-1)/2 次
    交换次数：最多 n-1 次
@param int* array 数组
@param int length 位序
    与索引不同
@return 无
*/
void selection_sort(int *array, int length)
{
    int max_index = LENGTH2INDEX(length);

    for(int i = 0 ;i <= max_index; i++ )
    {
        int min_point = i;
        for (int j = i + 1; j <= max_index; j++)
        {
            if(array[j] < array[min_point])
            {
                min_point = j;
            }
        }
        if (min_point != i)
        {
            swap_int(&array[i], &array[min_point]);
        }
    }
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
    char name[10] = "\0";
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

    char ch1 = getchar(); // int

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
double *solve_quadratic_equation(double a, double b, double c)
{
    // 处理a=0的情况（线性方程）
    if (is_zero(Double, a))
    {
        printf("系数a不能为0，这不是一个二次方程\n");
        return NULL;
    }

    // 动态分配内存以避免返回局部变量地址
    double *result = (double *)malloc(2 * sizeof(double));
    if (result == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }

    memset(result, 0, 2 * sizeof(double));

    double disc = pow(b, 2.0) - 4 * a * c;
    double p = 0.0;
    double q = 0.0;

    if (disc >= 0)
    {
        p = sqrt(disc) / (2 * a);
        q = -b / (2 * a);
        result[0] = q + p;
        result[1] = q - p;
    }
    else
    {
        printf("No real root\n");
    }

    return result;
}

#endif

#if defined(TEST_SWAP_INT_EXAMPLE) || defined(SORT_FUCTION)
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
@return int* fibonacci_sequence 需要free释放
*/
int *get_fibonacci_sequence(int n)
{
    // 申请内存
    int *fibonacci_sequence = (int *)malloc((n + 1) * sizeof(int));
    if (fibonacci_sequence == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // 初始化 为0
    memset(fibonacci_sequence, 0, (n + 1) * sizeof(int));

    // 存储信息
    fibonacci_sequence[0] = n; // 存储总数信息

    // 计算数列
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
            fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
        }
    }
    return fibonacci_sequence;
}

void print_fibonacci_sequence(int *fibonacci_sequence)
{
    if (fibonacci_sequence == NULL)
    {
        return;
    }

    int num = fibonacci_sequence[0];

    printf("the fibonacci sequence are: \n");

    for (int i = 1; i <= num; i++)
    {
        printf("序号%-5d:\t%10d\n", i, fibonacci_sequence[i]);
    }

    printf("\n");
}
int get_fibonacci_sequence_num(int *fibonacci_sequence)
{
    if (fibonacci_sequence == NULL)
    {
        return FALSE;
    }

    return fibonacci_sequence[0];
}

#endif

#ifdef TEST_ARRAY
/*
@breif 测试数组
*/

void test_array()
{

    /* 一维数组 */
    int arr[10];

    memset(arr, 0, sizeof(arr));

    printf("一维数组");
    printf("数组大小:%d\n", sizeof(arr));
    printf("地址如下\n");
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d]:\t%p\n", i,&arr[i]);
    }


    print_horizontal_line(10);
    /* 二维数组 */

    int arr2[2][3] = {{1, 9, 0}, {7, 1, 6}};

    // memset(arr2, 0, sizeof(arr2));

#ifdef BUBBLE_SORT
    bubble_sort(arr2[0] , sizeof(arr2)/sizeof(arr2[0][0]));
#endif

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            
            printf("arr2[%d][%d]:\t%d\n", i, j, arr2[i][j]);
        }
        printf("\n");
    }

    printf("二维数组");
    printf("数组大小:%d\n", sizeof(arr2));
    printf("地址如下\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("arr2[%d][%d]:\t%p\n", i,j,&arr2[i][j]);
        }
    }


    print_horizontal_line(10);
}

#endif

#ifdef TEST_FUNCTION
/*
@breif 测试函数
*/

/* 函数嵌套测试 */
static double Max(double a, double b)
{
    return a > b ? a : b;
}

double Max4(double a, double b, double c, double d)
{
    return Max(Max(a, b), Max(c, d));
}

/* 函数递归测试 */
int factorial_recursive(int n)
{
    if (n < 0)
    {
        printf("Invalid input\n");
        return -1;
    }
    

    if (n <= 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}
void hanoi(int n, char from, char aux, char to) {
    // 基础情况
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    // 递归情况
    // 将前n-1个盘子从from移动到aux
    hanoi(n - 1, from, to, aux);
    // 将第n个盘子从from移动到to
    printf("Move disk %d from %c to %c\n", n, from, to);
    // 将n-1个盘子从aux移动到to
    hanoi(n - 1, aux, from, to);
}

/* 外部函数调用 */

void Input(char arr[])
{
    gets(arr);
}

void DelChar(char arr[], char ch)
{
    int i = 0, j = 0;

    while (arr[i] != '\0')
    {
        if (arr[i] != ch)
        {
            arr[j] = arr[i];
            j++;
        }
        i++;
    }
    arr[j] = '\0';
}

#endif

#ifdef LEARN_POINTER

void modify_data()
{
    print_horizontal_line(20);
    printf("修改前\n");
    int a = 10;
    int *p = &a;
    printf("a = %d\n", a);
    printf("*p = %d\n", *p);
    a = 20;
    print_horizontal_line(20);
    printf("修改后\n");
    printf("a = %d\n", a);
    printf("*p = %d\n", *p);

}

void pointer_test()
{
    print_horizontal_line(20);
    printf("指针测试\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%p ====> %p \n",p+i,&arr[i]);
        printf("%d ====> %d \n",*(p+i),arr[i]);
    }
    
    print_horizontal_line(20);
    printf("指针运算\n");

    int *p1 = &arr[0];
    int *p2 = &arr[4];

    printf("俩指针相差:\tp2-p1=%d\n",p2-p1);
}

/**
 * 反转数组中的元素顺序
 * 
 * @param array 指向整型数组的指针
 * @param length 数组的长度
 * 
 * 该函数通过双指针法从数组两端向中间交换元素，实现数组的原地反转。
 * 使用LENGTH2INDEX宏将数组长度转换为索引值，通过swap_int函数交换元素。
 */
void reverse_array(int *array, int length)
{
    // 初始化双指针，start指向数组开始，end指向数组结束
    int *start = array;
    int *end = array + LENGTH2INDEX(length);
    
    // 当start指针小于end指针时，继续交换元素
    while (start < end)
    {
        // 交换start和end位置的元素
        swap_int(start, end);
        // 移动指针向中间靠拢
        start++;
        end--;
    }
}


/*
 * 函数: print_addreess_two_array
 * 功能: 打印二维数组中不同元素和行的地址，用于理解二维数组的内存布局和指针关系
 * 参数: 无
 * 返回值: 无
 */
void print_addreess_two_array()
{
    /*
     * 1. a[0],a[1],a[2]的类型为int*(指向整型变量)
     * 2. a的类型为int (*)[4],指向含有四个元素的一维数组
     */
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // 打印第0行的首地址和第0行第0列元素的地址
    printf("%d,%d\n",a,*a);         

    // 打印第0行第0列元素的地址（两种不同写法）
    printf("%d,%d\n",a[0],*(a+0));  

    // 打印第0行的首地址和第0行第0列元素的地址
    printf("%d,%d\n",&a[0],&a[0][0]);

    // 打印第1行第0列元素的地址和第1行的首地址
    printf("%d,%d\n",a[1],a+1);     

    // 打印第1行第0列元素的地址（两种不同写法）
    printf("%d,%d\n",&a[1][0],*(a+1)+0);    

    // 打印第2行第0列元素的地址（两种不同写法）
    printf("%d,%d\n",a[2],*(a+2));      

    // 打印第2行的首地址（两种不同写法）
    printf("%d,%d\n",&a[2],a+2);        
}

/**
 * 打印二维数组的内容
 * @param arr 指向二维数组的指针
 * @param row 二维数组的行数
 * @param col 二维数组的列数
 */
void print_two_array(int *arr ,int row, int col)
{
    // 外层循环遍历每一行
    for (int i = 0; i < row; i++)
    {
        // 内层循环遍历当前行的每一列
        for (int j = 0; j < col; j++)
        {
            // printf("%d\t",*(arr+i*col+j));
            printf("%d\t",arr[i*col+j]);
        }
        // 每行打印完成后换行
        printf("\n");
    }

}

void char_test()
{
    char *str = "hello world";
    printf("%s\n",str);
}

/**
 * @brief 将源字符串复制到目标字符串
 * 
 * @param dest 指向目标字符串的指针
 * @param src  指向源字符串的指针
 * 
 * @note 该函数会将src指向的字符串（包括结束符'\0'）复制到dest指向的位置，
 *       调用者需要确保dest指向的内存空间足够大以容纳src指向的整个字符串。
 */
void copy_str(char *dest, char *src)
{
    // 复制源字符串的每个字符到目标字符串，直到遇到字符串结束符
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++; 
    }
    // 在目标字符串末尾添加结束符
    *dest = '\0';
    
}


#endif

