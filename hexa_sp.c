#include "holberton.h"

/**
 * format_x - Function that prints hexadecimal.
 *
 * @arg: list of argument.
 * @buffer: array that stores string
 * @i: pointer to number of character
 *
 * Return: 0 on success
 */
int format_x(va_list arg, char *buffer, int *i)
{
	unsigned int n;
	int x = 0;
	char *hexvalues;
	char *hex;

	n = va_arg(arg, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return (0);
	if (n == 0)
	{
		hex[0] = '0';
		x++;
	}
	for (; n != 0; x++)
	{
		hex[x] = hexvalues[n % 16];
		n /= 16;
	}
	for (x--; x >= 0; *i += 1, x--)
	{
		buffer[*i] = hex[x];
	}
	free(hex);
	return (0);
}

/**
 * format_X - Function that prints hexadecimal
 *
 * @arg: list of argument
 * @buffer: array that stores string
 * @i: pointer to number of character
 *
 * Return: 0 on success
 */
int format_X(va_list arg, char *buffer, int *i)
{
	unsigned int n;
	int x = 0;
	char *hexvalues;
	char *hex;

	n = va_arg(arg, int);
	hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return (0);
	if (n == 0)
	{
		hex[0] = '0';
		x++;
	}
	for (; n != 0; x++)
	{
		hex[x] = hexvalues[n % 16];
		n /= 16;
	}
	for (x--; x >= 0; *i += 1, x--)
	{
		buffer[*i] = hex[x];
	}
	free(hex);
	return (0);
}
