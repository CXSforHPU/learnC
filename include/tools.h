#ifndef TOOLS_H
#define TOOLS_H

#include "stdio.h"
#include "math.h"
#include "my_type.h"
#include "config.h"
#include "stdlib.h"
#include "string.h"

#ifdef _WIN32
#include <windows.h>
#endif

int sum(int num1, int num2);
int compare(int num1, int num2);
void use_scanf();
int factorial(int num);
double get_value(int n);
my_bool is_prime(int num);
float fahrenheit_to_celsius(float fahrenheit);
void test_escape_characters();
void test_upper_to_lower(char* ch);
float triangle_area(float a, float b, float c);

#endif // TOOLS_H


