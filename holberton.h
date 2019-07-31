#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list parameters);
int print_string(va_list parameters);
int is_valid(char c);
int print_integer(va_list parameters);
int get_digits(unsigned int copy);
int get_divider(int digits);
int (*get_print_func(const char c))(va_list ap);
/**
 * struct format - Structure that saves the print function for each identifier.
 *
 * @type: char that represents the type of data that will be printed.
 *
 * @function: the pointer to the function that prints certain data type.
 */
struct format
{
	char type;
	int (*function)(va_list);
};
typedef struct format format_t;
#endif
