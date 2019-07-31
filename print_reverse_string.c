#include "holberton.h"

/**
 * rev_string - Reverses a string.
 *
 * @s: The char pointer of the string that will be reversed.
 *
 * @output: The char pointer to the string reversed.
 *
 * Return: Always void (no value)
 *
 */

void rev_string(char *s, char *output)
{
	int digits;
	int i;
	int limit;

	digits = 0;

	while (*(s + digits) != '\0')
	{
		digits++;
	}

	limit = digits;

	digits--;

	for (i = 0; i < limit; i++)
	{
		output[i] = *(s + digits);
		digits--;
	}
}

/**
 * print_rev_string - Prints a string reversed from a list of parameters
 *				      from a variadic function.
 *
 * @parameters: the va_list of parameters where is data that will be printed.
 *
 * Return: the number of bytes of the string printed.
 */

int print_rev_string(va_list parameters)
{
	char *string;
	int i;
	int length;
	char *response;

	length = 0;

	/*Get the string from the parameters of the function*/
	string = (va_arg(parameters, char*));

	if (string != NULL)
	{
		/*Get the length of the string*/
		for (i = 0; *(string + i) != '\0'; i++)
		{
			length++;
		}

		/*Get the reversed string*/
		response = malloc(length);
		rev_string(string, response);

		/*
		* Print the string to stdout(1)
		* and return the number of bytes printed
		*/
		write(1, response, length);

		free(response);

		return (length);
	}

	/*If the string is NULL print (null) and return 6*/
	return (write(1, "(null)", 6));
}
