#include "holberton.h"

/**
 * _printf - This function prints data according to a format string.
 *
 * @format: a string with the format of how the data will be printed.
 *
 * Return: an int with the numbers of bytes printed.
 */

int _printf(const char *format, ...)
{
	int count, i;
	va_list parameters;

	if (format == NULL)
	{
		return (-1);
	}
	for (i = 0, count = 0, va_start(parameters, format); format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				count += _putchar('%');
			}
			else if (is_valid(format[i]))
			{
				count += get_print_func(format[i])(parameters);
			}
			else if (format[i] != '\0')
			{
				count += _putchar('%') + _putchar(format[i]);
			}
			else if (format[i] == '\0')
			{
				return (-1);
			}
			else
			{
				count += _putchar('%');
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	va_end(parameters);
	return (count);
}

/**
 * is_valid - Checks if the format identifier char is valid.
 *
 * @c: the char with the format identifier that will be checked.
 *
 *Return: 1 if @ is a valid format identifier, else return 0.
*/

int is_valid(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i');
}
