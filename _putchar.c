#include <unistd.h>
#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @buffer: The characters to print
 * @i: pointer to number of character
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
void _putchar(char *buffer, int *i)
{
	write(1, buffer, *i);
}
