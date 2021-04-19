#include "holberton.h"

/**
 * flag_plus - print + before integer if positive and - if negative.
 *
 * @arg: list of argument.
 * @buffer: array that stores string
 * @i: pointer to number of character
 *
 * Return: 1 on success
 */
int flag_plus(va_list arg, char *buffer, int *i)
{
	int x, j, numlen;
	char *num_str;

	x = va_arg(arg, long int);

	numlen = num_len(x);
	numlen += 1;
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return (-1);
	num_str[0] = '+';
	itos(num_str, x);

	for (j = 0; num_str[j] != '\0'; *i += 1, j++)
	{
		buffer[*i] = num_str[j];
	}
	free(num_str);
	return (1);
}
