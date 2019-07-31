#include "holberton.h"

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
 * print_char - Prints an char from a list of parameters
 *				  from a variadic function.
 *
 * @parameters: the va_list of parameters where is data that will be printed.
 *
 * Return: the number of bytes of the char printed or -1 if an error ocurrs.
 */

int print_char(va_list parameters)
{
	/*Get the char from the parameters of the function*/
	char c;

	c = (char) va_arg(parameters, int);
	/*
	* Print the char (using his adrress as a pointer to get it) to stdout(1)
	* and return the number of bytes printed
	*/
	return (write(1, &c, sizeof(char)));
}

/**
 * print_string - Prints a string from a list of parameters
 *				  from a variadic function.
 *
 * @parameters: the va_list of parameters where is data that will be printed.
 *
 * Return: the number of bytes of the string printed.
 */

int print_string(va_list parameters)
{
	char *string;
	int i;
	int length;

	length = 0;

	/*Get the string from the parameters of the function*/
	string = va_arg(parameters, char*);

	if (string != NULL)
	{
		/*Get the length of the string*/
		for (i = 0; *(string + i) != '\0'; i++)
		{
			length++;
		}
		/*
		* Print the string to stdout(1)
		* and return the number of bytes printed
		*/
		return (write(1, string, length));
	}
	/*If the string is NULL dont print nothing and return 0*/
	return (write(1, "(null)", 6));
}
