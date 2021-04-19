#include "holberton.h"

/**
 * format_b - Function that prints in binary.
 *
 * @arg: list of argument.
 * @buffer: array that stores string.
 * @i: pointer to number of character.
 *
 * Return: 0 on success.
 */
int format_b(va_list arg, char *buffer, int *i)
{
	unsigned int n, m;
	int *num, j, count = 0;
	char *num_str, *num_str2;

	n = va_arg(arg, int);
	m = n;
	if (n == 0)
		count++;
	for (; m != 0; count++)
	{
		m = m / 2;
	}
	num = malloc(sizeof(int) * count);
	num_str = malloc(sizeof(char) * count);
	num_str2 = malloc(sizeof(char) * count);
	if (num == NULL || num_str == NULL)
		exit(-1);
	for (j = 0; n > 0; j++)
	{
		num[j] = n % 2;
		n = n / 2;
	}

	for (j = 0; j < count; j++)
	{
		itos(num_str, num[j]);
		num_str2[j] = num_str[0];
	}
	free(num_str);
	for (count--; count >= 0; *i += 1, count--)
	{
		buffer[*i] = num_str2[count];
	}
	free(num_str2);
	return (0);
}
