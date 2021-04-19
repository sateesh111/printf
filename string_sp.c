#include "holberton.h"

/**
 * format_str - Function that prints string.
 *
 * @arg: list of argument.
 * @buffer: array that stores string
 * @i: pointer to number of character
 *
 * Return: 0 on success
 */
int format_str(va_list arg, char *buffer, int *i)
{
	int n, j;
	char *s;

	s = va_arg(arg, char*);
	if (s == NULL)
		s = "(null)";
	for (n = *i, j = 0; s[j] != '\0';  *i += 1, n++, j++)
	{
		buffer[*i] = s[j];
	}
	return (0);
}

/**
 * format_c - Function that prints character
 *
 * @arg: list of argument
 * @buffer: array that stores string
 * @i: pointer to number of character
 *
 * Return: 0 on success
 */
int format_c(va_list arg, char *buffer, int *i)
{
	char s;

	s = va_arg(arg, int);
	buffer[*i] = s;
	*i += 1;
	return (0);
}
