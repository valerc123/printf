#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;
    _printf("Len:[%s]", "hola");
    printf("\n");
    printf("Len:[%s]", "como");
    printf("\n");
    _printf("Unknown:[%c]", 'h');
    printf("\n");
    printf("Unknown:[%c]", 'c');
    _printf("percent %% five\n");
    printf("percent %% five\n");

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	printf("%%");
	_printf("%%%");
	_printf("c%sc", "hello");
	printf("c%sc", "hello");
	_printf("%s", NULL);

	return (0);
}
