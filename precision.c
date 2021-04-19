#include "holberton.h"

/**
 * precision_diu - function that prints number with precision
 *
 * @arg: argument.
 * @buffer: array of string containing integer.
 * @i:pointer to number of character.
 * @z: first argument
 */
void precision_diu(va_list arg, char *buffer, int *i, int z)
{
	int x, len = 0, tmp;
	char *num_str;

	x = va_arg(arg, int);
	tmp = x;
	if (tmp < 0)
	{
		len++;
		tmp = -tmp;
	}
	len = num_len(tmp);
	num_str = malloc(sizeof(char) * len);
	if (x < 0)
	{
		buffer[*i] = '-';
		*i += 1;
	}
	if (len < z)
	{
		len = z - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = '0';
		if (x == 0)
		{
			buffer[*i] = '0';
			*i += 1;
		}
	}
	for (len = 0; x != 0; len++)
	{
		if (x < 0)
			x = -x;
		num_str[len] = (x % 10) + '0';
		x /= 10;
	}
	for (len--; len >= 0; len--, *i += 1)
		buffer[*i] = num_str[len];
	free(num_str);
}

/**
 * precision_o - function that prints octa number with precision
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @i:pointer to number of character
 * @z: first argument
 */
void precision_o(va_list arg, char *buffer, int *i, int z)
{
	int x, m, len = 0;
	char *octvalues;
	char *oct;

	m = va_arg(arg, int);
	octvalues = "0123456789ABCDEF";

	oct = malloc(12 * sizeof(char));
	for (x = 0; m != 0; x++, len++)
	{
		oct[x] = octvalues[m % 8];
		m /= 8;
	}
	if (len < z)
	{
		len = z - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = '0';
	}
	for (x--; x >= 0; *i += 1, x--)
		buffer[*i] = oct[x];
	free(oct);
}

/**
 * precision_xX - function that prints hexa with precision
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @i:pointer to number of character
 * @z: first argument
 * @h: specifier
 */
void precision_xX(va_list arg, char *buffer, int *i, int z, char h)
{
	int x, len = 0, m;
	char *hexvalues;
	char *hex;

	m = va_arg(arg, int);
	if (h == 'x')
		hexvalues = "0123456789abcdef";
	if (h == 'X')
		hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));

	for (x = 0; m != 0; x++, len++)
	{
		hex[x] = hexvalues[m % 16];
		m /= 16;
	}
	if (len < z)
	{
		len = z - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = '0';
	}
	for (x--; x >= 0; *i += 1, x--)
		buffer[*i] = hex[x];
	free(hex);
}

/**
 * precision_s - function that prints string with precision
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @i:pointer to number of character
 * @z: first argument
 */
void precision_s(va_list arg, char *buffer, int *i, int z)
{
	int len, j;
	char *str;

	str = va_arg(arg, char *);
	len = _strlen(str);

	if (len <= z)
	{
		for (j = 0; str[j] != '\0';  *i += 1, j++)
			buffer[*i] = str[j];
	}
	if (len > z)
	{
		for (j = 0; j < z; j++, *i += 1)
			buffer[*i] = str[j];
	}
}

/**
 * precision - function that checks for specifier
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string.
 * @i:pointer to number of character
 *
 * Return: 2 on success
 */
int precision(va_list arg, char *buffer, const char *format, int n, int *i)
{
	int z;
	char h;

	if (format[n + 1] == '*')
		z = va_arg(arg, int);
	else
		z = format[n + 1] - '0';
	h = format[n + 2];

	if ((format[n + 2] == 'd' || format[n + 2] == 'i') || format[n + 2] == 'u')
		precision_diu(arg, buffer, i, z);
	else if (format[n + 2] == 'o')
		precision_o(arg, buffer, i, z);
	else if (format[n + 2] == 'x' || format[n + 2] == 'X')
		precision_xX(arg, buffer, i, z, h);
	else if (format[n + 2] == 's')
		precision_s(arg, buffer, i, z);
	else
		exit (1);
	return (2);
}
