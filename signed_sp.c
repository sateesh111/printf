#include "holberton.h"
#include <stdlib.h>
#include <string.h>

/**
 * format_d - Function that prints signed integer.
 *
 * @arg: List of arguments.
 * @buffer: array of string containing integer
 * @i: pointer to number of character
 *
 * Return: 0 on success
 */
int format_d(va_list arg, char *buffer, int *i)
{
	int x, j, numlen;
	char *num_str;

	x = va_arg(arg, int);

	numlen = num_len(x);
	if (x < 0)
	{
		numlen += 1;
	}
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return (-1);
	itos(num_str, x);
	for (j = 0; num_str[j] != '\0' ; *i += 1, j++)
	{
		buffer[*i] = num_str[j];
	}
	free(num_str);
	return (0);
}
