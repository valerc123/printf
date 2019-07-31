#include "holberton.h"

/**
 * print_integer - Prints an integer from a list of parameters
 *				  from a variadic function.
 *
 * @parameters: the va_list of parameters where is data that will be printed.
 *
 * Return: the number of bytes of the string printed.
 */

int print_integer(va_list parameters)
{
	int number;
	int digits;
	int sign;
	unsigned int copy;
	char nums[1024];
	int i;
	int base;

	number = va_arg(parameters, int), digits = 0, sign = 1;
	copy = number < 0 ? (unsigned int) number * -1 : (unsigned int) number;

	if (number < 0)
	{
		sign = -1;
	} else if (number == 0)
	{
		return (write(1, "0", 1));
	}

	i = 0;

	if (sign == -1)
	{
		*(nums + i) = '-', i++;
	}
	digits = get_digits(copy), base = get_divider(digits);

	while (base > 0)
	{
		*(nums + i) = '0' + (copy / base);
		copy %= base;
		base /= 10;
		i++;
	}
	if (sign == -1)
	{
		digits++;
	}
	return (write(1, nums, digits));
}

/**
 * get_digits - Computes the number of digits in an integer.
 *
 * @copy: the unsigned int that will be processed.
 *
 * Return: the number digits of @copy.
 */

int get_digits(unsigned int copy)
{
	int digits;

	digits = 0;

	while (copy > 0)
	{
		digits++;
		copy /= 10;
	}

	return (digits);
}

/**
 * get_divider - Computes the divider to get the first digit of any number.
 *
 * @digits: the number of digits of the number that will be divided..
 *
 * Return: 1 * 10^digits-1 as if 1234 => 1000.
 */

int get_divider(int digits)
{
	int base;
	int exp;

	base = 1;

	exp = digits;

	while (exp > 1)
	{
		base *= 10;
		exp--;
	}

	return (base);
}
