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
��Ҫ������C�����пɱ��������ʱ��
float ���ͻᱻ�Զ�����Ϊ double ���ͣ�
���Լ�ʹ����Ϊ float��ʵ�ʴ����Ҳ�� double��
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
@brief ð������
    ʱ�临�Ӷ� O(n^2)
    �ȶ�
    �ռ临�Ӷ� O(1)
@param int* array ����
@param int length λ��
    ��������ͬ
@return ��
*/
void bubble_sort(int *array, int length)
{
    int max_index = LENGTH2INDEX(length);
    /* ȷ���������� max_index - 1 */
    for (int i = max_index; i > 0; i--)
    {
        /* ȷ���Ƚϵ�Ԫ�ظ��� ���� i�Ǵ�������ȷ���� ���� */
        for (int j = 1; j <= i; j++)
        {
            array[j] > array[j - 1] ?: swap_int(&array[j], &array[j - 1]);
        }
    }
}

/*
@brief ѡ������
    �㷨�ص�
    ʱ�临�Ӷȣ�O(n) - ������á������ƽ�����
    �ռ临�Ӷȣ�O(1) - ԭ�������㷨
    �ȶ��ԣ����ȶ�����
    �Ƚϴ������̶�Ϊ n(n-1)/2 ��
    ������������� n-1 ��
@param int* array ����
@param int length λ��
    ��������ͬ
@return ��
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
@brief ���
@param int num1 ����1
@param int num2 ����2
@return ���غ�
*/
int sum(int num1, int num2)
{
    int sum_number = num1 + num2;

    return sum_number;
}
#endif

#ifdef COMPARE_EXAMPLE
/*
@brief ��ȡ���������е����ֵ
@param int num1 ����1
@param int num2 ����2
@return �������������е����ֵ
*/
int compare(int num1, int num2)
{
    return num1 >= num2 ? num1 : num2;
}
#endif

#ifdef USE_SCANF_EXAMPLE
/*
@brief ��������Լ��Ƚϴ�С�����
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
@brief �׳˺���
@param int num
@return �׳˽��
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
@brief ��ȡ����ֵ
1-1/2+1/3 + 1/(n+1)*(-1)^n
@param n ���е�����
@return �������
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
@brief �ж��Ƿ�������
@param int num ����
@return �ǲ�������
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
@brief �����¶�ת�������¶�
@param float fahrenheit �����¶�
@reture �����¶�
*/
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}
#endif

#ifdef TEST_ESCAPE_CHARACTERS_EXAMPLE
/*
@brief ����ת���ַ���ʹ��
*/
void test_escape_characters()
{
    // ���Ի��з� \n
    printf("���ǵ�һ��\n���ǵڶ���\n");

    // �����Ʊ�� \t
    printf("����\t����\t����\n");
    printf("����\t25\t����\n");

    // ���Է�б�ܱ���
    printf("·��: C:\\Program Files\\MyApp\\\n");

    // ����˫���� \"
    printf("��˵: \"Hello World\"\n");

    // ���Ե����� \'
    printf("�ַ� \'A\' ��ASCII���� %d\n", 'A');

    // ���Իس��ͻ��� \r\n (Windows���)
    printf("��һ��\r\n�ڶ���\r\n");

    // ���������ַ� \a
    printf("�������: \a�뿴����!\n");

    // �����˸��ַ� \b
    printf("�����˸�: ABCD\b\b\b\b1234\n");

    // ���԰˽���ת���ַ�
    printf("�˽���101��ʾ�ַ�: \101\n");

    // ����ʮ������ת���ַ�
    printf("ʮ������41��ʾ�ַ�: \x41\n");
}
#endif

#ifdef TEST_UPPER_TO_LOWER_EXAMPLE
/*
@brief ��д��ĸתСд��ĸ ��������ַ� ���ַ���
*/
void test_upper_to_lower(char *ch)
{

    if (*ch >= 65 && *ch <= 90) // A - 65�� Z - 90
    {
        *ch = *ch + 32;
    }
}
#endif

#ifdef TRIANGLE_AREA_EXAMPLE
/*
@breif �����������
@param float a, float b, float c �����������ߵĳ���
@return ���������
*/
float triangle_area(float a, float b, float c)
{
    // ���߳��Ƿ�Ϊ����
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("���������εı߳�����Ϊ����\n");
        return -1.0f;
    }

    // ����Ƿ�������������������������֮�ʹ��ڵ����ߣ�
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        printf("������������߳��Ȳ��ܹ���������\n");
        return -1.0f;
    }

    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
#endif

#ifdef TEST_INPUT_OUTPUT_EXAMPLE
/*
@breif �����������
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
    // printf("����������������%s\n����%s\n",name,description);

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
@breif :һԪ���η������
        a*x^2+bx+c=0
@param :double a x^2
@param :double b x
@param :double c ������
@return :����ֵ
*/
double *solve_quadratic_equation(double a, double b, double c)
{
    // ����a=0����������Է��̣�
    if (is_zero(Double, a))
    {
        printf("ϵ��a����Ϊ0���ⲻ��һ�����η���\n");
        return NULL;
    }

    // ��̬�����ڴ��Ա��ⷵ�ؾֲ�������ַ
    double *result = (double *)malloc(2 * sizeof(double));
    if (result == NULL)
    {
        printf("�ڴ����ʧ��\n");
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
@breif ����������ֵ
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
@breif ʹ��switch case
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
@breif �ж�����
    ��ͨ���ܱ�4�����Ҳ��ܱ�100������Ϊ���ꡣ����Ϊƽ�ꡣ����2004��������꣬1900�겻�����꣩
    �������ܱ�400�����������ꡣ����Ϊƽ�ꡣ����2000�������꣬1900�겻�����꣩
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
@brief ���ԷѲ��ɴ�����
@param int n
@return int* fibonacci_sequence ��Ҫfree�ͷ�
*/
int *get_fibonacci_sequence(int n)
{
    // �����ڴ�
    int *fibonacci_sequence = (int *)malloc((n + 1) * sizeof(int));
    if (fibonacci_sequence == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // ��ʼ�� Ϊ0
    memset(fibonacci_sequence, 0, (n + 1) * sizeof(int));

    // �洢��Ϣ
    fibonacci_sequence[0] = n; // �洢������Ϣ

    // ��������
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
        printf("���%-5d:\t%10d\n", i, fibonacci_sequence[i]);
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
@breif ��������
*/

void test_array()
{

    /* һά���� */
    int arr[10];

    memset(arr, 0, sizeof(arr));

    printf("һά����");
    printf("�����С:%d\n", sizeof(arr));
    printf("��ַ����\n");
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d]:\t%p\n", i,&arr[i]);
    }


    print_horizontal_line(10);
    /* ��ά���� */

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

    printf("��ά����");
    printf("�����С:%d\n", sizeof(arr2));
    printf("��ַ����\n");

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
@breif ���Ժ���
*/

/* ����Ƕ�ײ��� */
static double Max(double a, double b)
{
    return a > b ? a : b;
}

double Max4(double a, double b, double c, double d)
{
    return Max(Max(a, b), Max(c, d));
}

/* �����ݹ���� */
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
    // �������
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    // �ݹ����
    // ��ǰn-1�����Ӵ�from�ƶ���aux
    hanoi(n - 1, from, to, aux);
    // ����n�����Ӵ�from�ƶ���to
    printf("Move disk %d from %c to %c\n", n, from, to);
    // ��n-1�����Ӵ�aux�ƶ���to
    hanoi(n - 1, aux, from, to);
}

/* �ⲿ�������� */

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
    printf("�޸�ǰ\n");
    int a = 10;
    int *p = &a;
    printf("a = %d\n", a);
    printf("*p = %d\n", *p);
    a = 20;
    print_horizontal_line(20);
    printf("�޸ĺ�\n");
    printf("a = %d\n", a);
    printf("*p = %d\n", *p);

}

void pointer_test()
{
    print_horizontal_line(20);
    printf("ָ�����\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%p ====> %p \n",p+i,&arr[i]);
        printf("%d ====> %d \n",*(p+i),arr[i]);
    }
    
    print_horizontal_line(20);
    printf("ָ������\n");

    int *p1 = &arr[0];
    int *p2 = &arr[4];

    printf("��ָ�����:\tp2-p1=%d\n",p2-p1);
}

/**
 * ��ת�����е�Ԫ��˳��
 * 
 * @param array ָ�����������ָ��
 * @param length ����ĳ���
 * 
 * �ú���ͨ��˫ָ�뷨�������������м佻��Ԫ�أ�ʵ�������ԭ�ط�ת��
 * ʹ��LENGTH2INDEX�꽫���鳤��ת��Ϊ����ֵ��ͨ��swap_int��������Ԫ�ء�
 */
void reverse_array(int *array, int length)
{
    // ��ʼ��˫ָ�룬startָ�����鿪ʼ��endָ���������
    int *start = array;
    int *end = array + LENGTH2INDEX(length);
    
    // ��startָ��С��endָ��ʱ����������Ԫ��
    while (start < end)
    {
        // ����start��endλ�õ�Ԫ��
        swap_int(start, end);
        // �ƶ�ָ�����м俿£
        start++;
        end--;
    }
}


/*
 * ����: print_addreess_two_array
 * ����: ��ӡ��ά�����в�ͬԪ�غ��еĵ�ַ����������ά������ڴ沼�ֺ�ָ���ϵ
 * ����: ��
 * ����ֵ: ��
 */
void print_addreess_two_array()
{
    /*
     * 1. a[0],a[1],a[2]������Ϊint*(ָ�����ͱ���)
     * 2. a������Ϊint (*)[4],ָ�����ĸ�Ԫ�ص�һά����
     */
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // ��ӡ��0�е��׵�ַ�͵�0�е�0��Ԫ�صĵ�ַ
    printf("%d,%d\n",a,*a);         

    // ��ӡ��0�е�0��Ԫ�صĵ�ַ�����ֲ�ͬд����
    printf("%d,%d\n",a[0],*(a+0));  

    // ��ӡ��0�е��׵�ַ�͵�0�е�0��Ԫ�صĵ�ַ
    printf("%d,%d\n",&a[0],&a[0][0]);

    // ��ӡ��1�е�0��Ԫ�صĵ�ַ�͵�1�е��׵�ַ
    printf("%d,%d\n",a[1],a+1);     

    // ��ӡ��1�е�0��Ԫ�صĵ�ַ�����ֲ�ͬд����
    printf("%d,%d\n",&a[1][0],*(a+1)+0);    

    // ��ӡ��2�е�0��Ԫ�صĵ�ַ�����ֲ�ͬд����
    printf("%d,%d\n",a[2],*(a+2));      

    // ��ӡ��2�е��׵�ַ�����ֲ�ͬд����
    printf("%d,%d\n",&a[2],a+2);        
}

/**
 * ��ӡ��ά���������
 * @param arr ָ���ά�����ָ��
 * @param row ��ά���������
 * @param col ��ά���������
 */
void print_two_array(int *arr ,int row, int col)
{
    // ���ѭ������ÿһ��
    for (int i = 0; i < row; i++)
    {
        // �ڲ�ѭ��������ǰ�е�ÿһ��
        for (int j = 0; j < col; j++)
        {
            // printf("%d\t",*(arr+i*col+j));
            printf("%d\t",arr[i*col+j]);
        }
        // ÿ�д�ӡ��ɺ���
        printf("\n");
    }

}

void char_test()
{
    char *str = "hello world";
    printf("%s\n",str);
}

/**
 * @brief ��Դ�ַ������Ƶ�Ŀ���ַ���
 * 
 * @param dest ָ��Ŀ���ַ�����ָ��
 * @param src  ָ��Դ�ַ�����ָ��
 * 
 * @note �ú����Ὣsrcָ����ַ���������������'\0'�����Ƶ�destָ���λ�ã�
 *       ��������Ҫȷ��destָ����ڴ�ռ��㹻��������srcָ��������ַ�����
 */
void copy_str(char *dest, char *src)
{
    // ����Դ�ַ�����ÿ���ַ���Ŀ���ַ�����ֱ�������ַ���������
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++; 
    }
    // ��Ŀ���ַ���ĩβ��ӽ�����
    *dest = '\0';
    
}


#endif

