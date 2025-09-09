#include "tools.h"
#include "ds.h"
#include "alg.h"

extern void Input();
extern void DelChar(char arr[], char ch);


void learn_alg()
{
    ;
#ifdef LEARN_ALG
    print_horizontal_line(20);
    printf("����3������\n");
    int arr_left_move[10] = {1,2,3,4,5,6,7,8,9,10};
    int length_left_move = sizeof(arr_left_move) / sizeof(arr_left_move[0]);
    print_int_array(arr_left_move, length_left_move);
    left_move(arr_left_move, length_left_move, 2);
    print_int_array(arr_left_move, length_left_move);

    print_horizontal_line(20);
    printf("ȡ�����������λ��\n");

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[10] = {4,5,6,7,8,9,10,11,12,13};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    
    print_int_array(arr1, length1);
    print_int_array(arr2, length2);
    printf("%d\n",get_two_arr_middle_number(arr1,arr2,length1,length2));
    
    /* ѭ������ƴ�� */

    test_concat_clinklist();


    /* ɾ���������������Ԫ��  */
    test_del_clinklist_ascending_order();

    /* ���Խ���ת��  */
    test_transform_ten2two();
#endif
}




void learn_ds()
{
    ;
#ifdef LEARN_DS
    LinkList head = init_list();
	tail_insect(head,6);
	tail_insect(head,7);
	tail_insect(head,10);
	tail_insect(head,24);
	tail_insect(head,54);
	tail_insect(head,86);
	
	print_list(head);
	
	insert_P_LNode_length(head,5,45);
	print_list(head);
	delete_P_LNode_value(head,24);
	print_list(head);


#endif
}
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
    int arr_pointer[10] = {1,2,3,4,5,6,7,8,9,10};
    int length_arr = sizeof(arr_pointer) / sizeof(arr_pointer[0]);
    modify_data();
    pointer_test();

    print_horizontal_line(20);
    printf("�������ò���\n");
    printf("��תǰ����Ϊ:\n");
    print_int_array(arr_pointer, length_arr);
    reverse_array(arr_pointer, length_arr);
    printf("��ת������Ϊ:\n");
    print_int_array(arr_pointer, length_arr);
    print_horizontal_line(20);
    print_addreess_two_array();
    
    print_horizontal_line(20);

    printf("��ά�����ӡ����\n");
    int two_array[4][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    int row = sizeof(two_array) / sizeof(two_array[0]);          //��ά�����С����һά�����С���õ���ά���������
    int column = sizeof(two_array[0]) / sizeof(two_array[0][0]); //һά����������һ��Ԫ��
    print_two_array(&two_array[0][0], row, column);

    print_horizontal_line(20);
    printf("�ַ�����\n");
    char_test();
    char str1[20] = "hello world";
    char str2[20] = { 0 };

    copy_string(str1, str2);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    print_horizontal_line(20);
    printf("����ָ�����\n");
    test_func_pointer();
#endif

}

int main()
{
    test_tools();
    print_horizontal_line(20);
    printf("���ݽṹ����\n");
    learn_ds();

    print_horizontal_line(20);
    learn_alg();


    system("pause");
    return 0;
}