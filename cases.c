#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * cases - This function for check different cases
 * @list: argument of the functions
 * @format: values
 * Return: int
 */
int cases(va_list list, const char *format)
{
	char *str, c;
	int i, count;

	for (i = 0, count = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 's':
					str = va_arg(list, char *);
					if (str == NULL)
						str = "(null)";
					count += print_string(str);
					i++, count--;
					break;
				case 'c':
					c = (char) va_arg(list, int);
					print_char(c);
					i++;
					break;
				case '%':
					print_char('%');
					i++;
					break;
				case '\0':
					count = -2;
					break;
				default:
					print_char('%');
					break;
			}
		}
		else
			print_char((char) format[i]);
		count += 1;
	}
	va_end(list);
	return (count);
}
