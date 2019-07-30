#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
 * _printf - This function prints data according to a format
 * @format: type of data
 * Return: the integer written
 */
int _printf(const char *format, ...)
{
	int n = 0;
	va_list list;

	va_start(list, format);
	if (!format)
		return (-1);
	n = cases(list, format);
	va_end(list);
	return (n);
}
