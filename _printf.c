#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
		return (write(1, &c, 1));
}
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
		write(1, string, length);
		return (length);
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
	int count = 0;
	va_list list;

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (!format)
			return (-1);
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 's':
					str = va_arg(list, char *);
					if (str == NULL)
						str = "(null)";
					count += print_string(str);
					count--;
					i++;
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
				default:
					print_char('%');
					break;
			}
		}
		else
		{
			print_char((char) format[i]);
		}
		i++;
	}
	va_end(list);
	count++;
	return (count);
}
