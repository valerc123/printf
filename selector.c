#include "holberton.h"

/**
 * get_print_func - Find the function to print certain data
 *					based on a format given by a char.
 *
 * @c: the char that identifies the format of the data that will be printed.
 *
 * Return: a function pointer to the function that prints the data
 *		   defined by the identifier @c.
 */

int (*get_print_func(const char c))(va_list parameters)
{
	int i;

	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_integer},
		{'i', print_integer},
		{'r', print_rev_string},
		{'R', print_rot13_string}
	};
	/*
	 * Check into the array to find the correct struct
	 * or until the end of the array-
	 */
	for (i = 0; i < 6; i++)
	{
		if (c == formats[i].type)
		{
			return (formats[i].function);
		}
	}
	/* If dont find the correct function */
	return (0);
}
