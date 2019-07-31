#include "holberton.h"

/**
 * rot13 - Encodes a string using rot13.
 *
 * @s: the string that will be procesed.
 *
 * @output: The char pointer to the encrypted string.
 *
 *Return: Always 0(Nothing).
 *
 */

void rot13(char *s, char *output)
{
	int i;
	int j;

	char base[]		=	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char coded[]	=	"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; base[j] != 0; j++)
		{
			if (*(s + i) == base[j])
			{
				*(output + i) = coded[j];
				break;
			}
		}
	}
}


/**
 * print_rot13_string - Prints a string encrypted in rot13
 *						from a list of parameters from a variadic function.
 *
 * @parameters: the va_list of parameters where is data that will be printed.
 *
 * Return: the number of bytes of the string printed.
 */

int print_rot13_string(va_list parameters)
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
		response = malloc(length);

		rot13(string, response);
		/*
		* Print the string to stdout(1)
		* and return the number of bytes printed
		*/
		write(1, response, length);
		return (length);
	}
	/*If the string is NULL print (ahyy) and return 6*/
	return (write(1, "(ahyy)", 6));
}
