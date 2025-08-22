#ifndef TOOLS_H
#define TOOLS_H

#define LENGTH2INDEX(x) (x-1);
#define INDEX2LENGTH(x) (x+1);


#include "config.h"

#ifdef USE_STDARG_H
#include <stdarg.h>
#endif

#ifdef USE_STDIO_H
#include "stdio.h"
#endif

#ifdef USE_MATH_H
#include "math.h"
#endif

#ifdef USE_STDLIB_H
#include "stdlib.h"
#endif

#ifdef USE_STRING_H
#include "string.h"
#endif

#ifdef USE_MY_TYPE_H
#include "my_type.h"
#endif

#ifdef _WIN32
#include <windows.h>
#endif

#if defined(USE_STDARG_H) && defined(USE_MATH_H) && defined(USE_MY_TYPE_H)
my_bool is_zero(math_type number_type,...);
#endif

void print_horizontal_line(int length);


#ifdef SUM_EXAMPLE
int sum(int num1, int num2);
#endif

#ifdef COMPARE_EXAMPLE
int compare(int num1, int num2);
#endif

#ifdef USE_SCANF_EXAMPLE
void use_scanf();
#endif

#ifdef FACTORIAL_EXAMPLE
int factorial(int num);
#endif

#ifdef GET_VALUE_EXAMPLE
double get_value(int n);
#endif

#ifdef IS_PRIME_EXAMPLE
my_bool is_prime(int num);
#endif

#ifdef FAHRENHEIT_TO_CELSIUS_EXAMPLE
float fahrenheit_to_celsius(float fahrenheit);
#endif

#ifdef TEST_ESCAPE_CHARACTERS_EXAMPLE
void test_escape_characters();
#endif

#ifdef TEST_UPPER_TO_LOWER_EXAMPLE
void test_upper_to_lower(char *ch);
#endif

#ifdef TRIANGLE_AREA_EXAMPLE
float triangle_area(float a, float b, float c);
#endif

#ifdef TEST_INPUT_OUTPUT_EXAMPLE
void test_input_output();
#endif


#ifdef TEST_SOLVE_QUADRATIC_EQUATION_EXAMPLE
double* solve_quadratic_equation(double a, double b, double c);
#endif

#if defined(TEST_SWAP_INT_EXAMPLE) || defined(SORT_FUCTION)
void swap_int(int *a, int *b);
#endif

#endif // TOOLS_H

#ifdef USE_SWITCH_CASE_EXAMPLE
void use_switch_case(int num);
#endif

#ifdef IS_LEAP_YEAR_EXAMPLE
my_bool is_leap_year(int year);
#endif

#ifdef FIBONACCI_SEQUENCE
int* get_fibonacci_sequence(int n);
void print_fibonacci_sequence(int* fibonacci_sequence);
int get_fibonacci_sequence_num(int* fibonacci_sequence);
#endif

#ifdef TEST_ARRAY
void test_array();
#endif

#ifdef SORT_FUCTION
void print_int_array(int* array, int length);
void bubble_sort(int* array, int length);
void selection_sort(int *array, int length);
#endif

#ifdef TEST_FUNCTION
double Max4(double a, double b, double c, double d);
int factorial_recursive(int n);
void hanoi(int n, char from, char aux, char to);
#endif


#ifdef LEARN_POINTER
void modify_data();
#endif