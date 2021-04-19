#include "holberton.h"

/**
 * format_pers - Function that stores percent sign in an array.
 *
 * @arg: unused list of arguments
 * @buffer: array to store '%'.
 * @i: pointer to the number of character
 *
 * Return: 0 on success
 */
int format_pers(__attribute__((unused))va_list arg, char *buffer, int *i)
{
	buffer[*i] = '%';
	*i += 1;
	return (0);
}
