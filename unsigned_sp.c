#include "holberton.h"

/**
 * format_u - Function that prints unsigned integer.
 *
 * @arg: list of argument.
 * @buffer: array that stores string.
 * @i: pointer to number of character
 *
 * Return: 0 on success
 */
int format_u(va_list arg, char *buffer, int *i)
{
	unsigned int x;
	int j, numlen;
	char *num_str;

	x = va_arg(arg, int);
	numlen = num_len(x);
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return (0);
	utos(num_str, x);
	for (x = *i, j = 0; j < numlen; *i += 1, x++, j++)
	{
		buffer[*i] = num_str[j];
	}
	free(num_str);
	return (0);
}
