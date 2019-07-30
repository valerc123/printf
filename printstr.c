#include <stdio.h>
#include "holberton.h"
#include <unistd.h>
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
