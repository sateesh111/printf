#include "holberton.h"

/**
 *flag_spc - function that print a space before a positive value
 *
 *@arg: list of argument.
 *@buffer: array of string containing integer.
 *@format:String composed of zero ot more characters to print
 *@n: Integers that contains the index of the string.
 *@i:pointer to number of character.
 *
 * Return: coutn, length
 */
int flag_spc(va_list arg, char *buffer, const char *format, int n, int *i)
{
	int x, j, numlen, count;
	char *num_str;

	if (format[n + 1] == 'd' || format[n + 1] == 'i')
	{
		x = va_arg(arg, long int);
		numlen = num_len(x);
		numlen += 1;
		num_str = malloc(numlen * sizeof(char));
		if (num_str == NULL)
			return (free(num_str), 0);
		if (x >= 0)
			num_str[0] = ' ';
		itos(num_str, x);
		for (j = 0, count = 1; num_str[j] != '\0'; *i += 1, j++)
		{
			buffer[*i] = num_str[j];
		}
		free(num_str);
	}
	else if (format[n + 1] == '%')
	{
		for (j = 0; j < 2; j++)
		{
			buffer[*i] = format[n - 1];
			*i += 1;
			buffer[*i] = format[n];
			*i += 1;
		}
		for (n++, count = 0; format[n + 1] != '\0'; n++, count++)
			;
	}
	else
	{
		buffer[*i] = format[n - 1];
		*i += 1;
		buffer[*i] = format[n];
		*i += 1;
	}
	return (count);
}
