#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * print_char - this function prints char
 * @c: char that going to be print
 * Return: int
 */
int print_char(char c)
{
	/**
	* Print the char (using a char* as buffer to store it)to stdout(1)
	* and return the number of bytes printed
	* (1 because that is the size of a char)
	*/
	return (write(1, &c, sizeof(char)));
}
/**
 * print_string - this function prints string
 * @string: s
 * Return: int
 */
int print_string(char *string)
{
	int i;
	int length;

	length = 0;

	if (string != NULL)
	{
		/*GET LENGTH OF THE STRING*/
		for (i = 0; *(string + i) != '\0'; i++)
		{
			length++;
		}
		/**
		* Print the string to stdout(1)
		* and return the number of bytes printed
		*/
		return (write(1, string, length));
	}
/*If the string is NULL dont print nothing and return 0*/
return (0);
}
/**
 * _printf - This function prints data according to a format
 * @format: type of data
 * Return: int
 */
int _printf(const char *format, ...)
{
	char *str;
	char c;
	int i = 0;
	va_list list;

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 's':
					str = va_arg(list, char *);
					print_string(str);
					i += 2;
					break;
				case 'c':
					c = (char) va_arg(list, int);
					print_char(c);
					i += 2;
					break;
				case '%':
					print_char('%');
					i += 2;
					break;
			}
		}
		print_char(format[i]);
		i++;
	}
	va_end(list);
	return (i);
}
