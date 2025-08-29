#include "tools.h"
#include "ds.h"

extern void Input();
extern void DelChar(char arr[], char ch);

void test_tools()
{
#ifdef _WIN32
    // ���ÿ���̨����ҳΪUTF-8
    SetConsoleOutputCP(936);
#endif

    // ���
    printf("hello world\n");

#ifdef SUM_EXAMPLE
    // ���
    printf("sum(10,20) = %d\n", sum(10, 20));
#endif

#ifdef COMPARE_EXAMPLE
    // �Ƚ�
    printf("compare(10,20) = %d\n", compare(10, 20));
#endif

#ifdef USE_SCANF_EXAMPLE
    // �������
    use_scanf();
#endif

#ifdef FACTORIAL_EXAMPLE
    // ���Խ׳�
    printf("factorial(5) = %d\n", factorial(5));
#endif

#ifdef GET_VALUE_EXAMPLE
    // ��ȡֵ
    printf("get_value(100) = %f\n", get_value(100));
#endif

#ifdef IS_PRIME_EXAMPLE
    // ��������
    printf("is_prime(13) = %d\n", is_prime(13));
#endif

#ifdef FAHRENHEIT_TO_CELSIUS_EXAMPLE
    // ���Ի����¶�ת�����¶�
    printf("fahrenheit_to_celsius(100) = %f\n", fahrenheit_to_celsius(100.0f));
#endif

#ifdef TEST_ESCAPE_CHARACTERS_EXAMPLE
    // ����ת���ַ�
    test_escape_characters();
    printf("%d\n", strlen("c:\test\32\test.c")); // �κ�ת���ַ�����һ���ַ� ���13
#endif

#ifdef TEST_UPPER_TO_LOWER_EXAMPLE
    // ���Դ�Сдת��
    char ch1 = 'a';
    char ch2 = 'A';
    test_upper_to_lower(&ch1);
    test_upper_to_lower(&ch2);
    printf("to_lower('a') = %c\n", ch1);
    printf("to_lower('A') = %c\n", ch2);
#endif

#ifdef TRIANGLE_AREA_EXAMPLE
    // �������������
    printf("��������� = %f\n", triangle_area(3.0f, 4.0f, 5.0f));
#endif

#ifdef TEST_INPUT_OUTPUT_EXAMPLE
    // �����������
    test_input_output();
#endif

#ifdef TEST_SOLVE_QUADRATIC_EQUATION_EXAMPLE
    // ���������η���
    double *result = solve_quadratic_equation(1, -3, 2);
    printf("x1 = %lf, x2 = %lf\n", result[0], result[1]);
    free(result); // �ͷ��ڴ�
#endif

#ifdef TEST_SWAP_INT_EXAMPLE
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap_int(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

#endif

#ifdef USE_SWITCH_CASE_EXAMPLE
    // ����switch case
    use_switch_case(1);

#endif

#ifdef IS_LEAP_YEAR_EXAMPLE
    // ��������
    printf("is_leap_year(2020) = %d\n", is_leap_year(2020));
#endif

#ifdef FIBONACCI_SEQUENCE
    int *fibonacci_sequence = get_fibonacci_sequence(40);
    printf("fibonacci_sequence numbers = %d\n", get_fibonacci_sequence_num(fibonacci_sequence));
    print_fibonacci_sequence(fibonacci_sequence);
    free(fibonacci_sequence);
#endif

#ifdef TEST_ARRAY
    test_array();
#endif

#ifdef SORT_FUCTION
    print_horizontal_line(20);
    printf("ð������\n");
    int arr[10] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 0};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("����ǰ��\n");
    print_int_array(arr, length);
    printf("�����\n");
    bubble_sort(arr, length);
    print_int_array(arr, length);

    print_horizontal_line(20);
    printf("ѡ������\n");
    int arr2[10] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 0};
    length = sizeof(arr2) / sizeof(arr2[0]);
    printf("����ǰ��\n");
    print_int_array(arr2, length);
    printf("�����\n");
    selection_sort(arr2, length);
    print_int_array(arr2, length);

#endif

#ifdef TEST_FUNCTION
    print_horizontal_line(20);
    // printf("���Ժ���Ƕ��");
    // double a = 0;
    // double b = 0;
    // double c = 0;
    // double d = 0;
    // printf("������a,b,c,d��ֵ:\n");
    // scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    // printf("���ֵΪ:%lf\n",Max4(a, b, c, d));

    print_horizontal_line(20);
    printf("���Ժ����ݹ�");

    printf("factorial(5) = %d\n", factorial_recursive(10));

    print_horizontal_line(20);
    printf("���Ժ����ݹ�\n");
    hanoi(5, 'A', 'B', 'C');

    print_horizontal_line(20);

    printf("�ⲿ�������ò���\n");
    char str[20] = {'\0'};

    Input(str);
    DelChar(str, ' ');
    printf("������ַ���Ϊ:%s\n", str);
#endif

#ifdef LEARN_POINTER
    modify_data();
#endif

#ifdef LEARN_DS
    print_horizontal_line(20);
    head_pointer head = init_list();
    head_insect(head, 1);
    head_insect(head, 2);
    head_insect(head, 3);
    tail_insect(head, 4);
    print_list(head);
    int length_node = get_length(head);
    insert_node_pointer_length(head, length_node, 45);
    print_list(head);
    insert_node_pointer_length(head, 1, 46);
    print_list(head);
    insert_node_pointer_length(head, 3, 47);
    print_list(head);
    printf("���ҵ���λ����:%d\n", find_node_pointer_length(head, 3)->data);
    printf("����ĩβλ����:%d\n", find_node_pointer_length(head, get_length(head))->data);
    printf("��������:%d\n", find_node_pointer_value(head, 2)->data);

    free_nodes(head);
    print_list(head);
#endif
}

int main()
{
    test_tools();

    system("pause");
    return 0;
}