#include "holberton.h"

/**
 * flag_left_diu - function that prints signed and unsigned number with - flag
 *
 * @k: argument.
 * @buffer: array of string containing integer.
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string.
 * @i:pointer to number of character.
 */
void flag_left_diu(int k, char *buffer, const char *format, int n, int *i)
{
	int l, len = 0, x;
	char *num_str;

	l = k;
	for (; l != 0; len++)
		l /= 10;
	if (k <= 0)
		len++;
	num_str = malloc(sizeof(char) * len);
	if (k == 0)
		num_str[0] = '0';
	for (x = 0; k != 0; x++)
	{
		if (k < 0)
		{
			num_str[len - 1] = '-';
			k = -k;
		}
		num_str[x] = (k % 10) + '0';
		k /= 10;
	}
	for (x = len - 1; x >= 0; x--, *i += 1)
		buffer[*i] = num_str[x];
	if (len < format[n + 1])
	{
		len = (format[n + 1] - '0') - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = ' ';
	}
	free(num_str);
}

/**
 * flag_left_o - function that prints octa number with - flag
 *
 * @k: argument
 * @buffer: array of string containing integer
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string
 * @i:pointer to number of character
 */
void flag_left_o(int k, char *buffer, const char *format, int n, int *i)
{
	int x = 0, len = 0;
	char *octvalues;
	char *oct;

	octvalues = "0123456789ABCDEF";

	oct = malloc(sizeof(char) * 12);
	if (k == 0)
	{
		oct[0] = '0';
		len++;
		x = 1;
	}
	for (; k != 0; x++, len++)
	{
		oct[x] = octvalues[k % 8];
		k /= 8;
	}
	for (x--; x >= 0; *i += 1, x--)
		buffer[*i] = oct[x];
	if (len < format[n + 1])
	{
		len = (format[n + 1] - '0') - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = ' ';
	}
	free(oct);
}

/**
 * flag_left_xX - function that prints hexa with - flag
 *
 * @k: argument
 * @buffer: array of string containing integer
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string
 * @i:pointer to number of character
 */
void flag_left_xX(int k, char *buffer, const char *format, int n, int *i)
{
	int x = 0, len = 0;
	char *hexvalues;
	char *hex;

	if (format[n + 2] == 'x')
		hexvalues = "0123456789abcdef";
	if (format[n + 2] == 'X')
		hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (k == 0)
	{
		hex[0] = '0';
		len++;
		x = 1;
	}
	for (; k != 0; x++, len++)
	{
		hex[x] = hexvalues[k % 16];
		k /= 16;
	}
	for (x--; x >= 0; *i += 1, x--)
		buffer[*i] = hex[x];
	if (len < format[n + 1])
	{
		len = (format[n + 1] - '0') - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = ' ';
	}
	free(hex);
}

/**
 * flag_left - function that checks for specifier
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string.
 * @i:pointer to number of character
 *
 * Return: 2 on success
 */
int flag_left(va_list arg, char *buffer, const char *format, int n, int *i)
{
	int k;

	k = va_arg(arg, int);
	if ((format[n + 2] == 'd' || format[n + 2] == 'i') ||
	    format[n + 2] == 'u')
		flag_left_diu(k, buffer, format, n, i);
	if (format[n + 2] == 'o')
		flag_left_o(k, buffer, format, n, i);
	if (format[n + 2] == 'x' || format[n + 2] == 'X')
		flag_left_xX(k, buffer, format, n, i);
	return (2);
}
