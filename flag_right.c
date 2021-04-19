#include "holberton.h"

/**
 * flag_right_diuc - function that prints signed,unsigned number, and char
 *
 * @arg: argument.
 * @buffer: array of string containing integer.
 * @z: first argument
 * @h: specifier
 * @i:pointer to number of character.
 */
void flag_right_diuc(va_list arg, char *buffer, int *i, int z, char h)
{
	int x, len2, s, l, len = 0;
	char *num_str;

	x = va_arg(arg, int);
	if (x < 0)
	{
		s = num_len(-x);
		s++;
	}
	else
		s = num_len(x);
	if (h == 'c')
	{
		for (len = z - 1; len > 0; len--, *i += 1)
			buffer[*i] = ' ';
		buffer[*i] = x;
		*i += 1;
	}
	else
	{
		num_str = malloc(sizeof(char) * s);
		len2 = s;
		if (s < z)
		{
			s = z - s;
			for (; s > 0; s--, *i += 1)
				buffer[*i] = ' ';
		}
		if (x == 0)
			num_str[0] = '0';
		for (l = 0; x != 0; l++)
		{
			if (x < 0)
			{
				num_str[len2 - 1] = '-';
				x = -x;
			}
			num_str[l] = (x % 10) + '0';
			x /= 10;
		}
		for (x = len2 - 1; x >= 0; x--, *i += 1)
			buffer[*i] = num_str[x];
		free(num_str);
	}
}

/**
 * flag_right_o - function that prints octa number
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @z: first argument
 * @i:pointer to number of character
 */
void flag_right_o(va_list arg, char *buffer, int *i, int z)
{
	int x = 0, len = 0, l;
	char *octvalues;
	char *oct;

	l = va_arg(arg, int);
	octvalues = "0123456789ABCDEF";
	oct = malloc(sizeof(char) * 12);
	if (l == 0)
	{
		oct[0] = '0';
		len++;
		x = 1;
	}
	for (; l != 0; x++, len++)
	{
		oct[x] = octvalues[l % 8];
		l /= 8;
	}
	if (len < z)
	{
		len = z - len;
		for (; len > 0; len--, *i += 1)
		{
			buffer[*i] = ' ';
		}
	}
	for (x--; x >= 0; *i += 1, x--)
		buffer[*i] = oct[x];
	free(oct);
}

/**
 * flag_right_xX - function that prints hexa
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @z: first argument
 * @h: specifier
 * @i:pointer to number of character
 */
void flag_right_xX(va_list arg, char *buffer, int *i, int z, char h)
{
	int x = 0, len = 0, l;
	char *hexvalues;
	char *hex;

	l = va_arg(arg, int);
	if (h == 'x')
		hexvalues = "0123456789abcdef";
	if (h == 'X')
		hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (l == 0)
	{
		hex[0] = '0';
		len++;
		x = 1;
	}
	for (; l != 0; x++, len++)
	{
		hex[x] = hexvalues[l % 16];
		l /= 16;
	}
	if (len < z)
	{
		len = z - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = ' ';
	}
	for (x--; x >= 0; *i += 1, x--)
		buffer[*i] = hex[x];
	free(hex);
}

/**
 * flag_right_s - function that prints string
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @z: first argument
 * @i:pointer to number of character
 *
 * Return: 2 on success
 */
void flag_right_s(va_list arg, char *buffer, int *i, int z)
{
	int len, j;
	char *str;

	str = va_arg(arg, char *);
	len = _strlen(str);

	if (len < z)
	{
		len = z - len;
		for (; len > 0; len--, *i += 1)
			buffer[*i] = ' ';
	}
	for (j = 0; str[j] != '\0';  *i += 1, j++)
		buffer[*i] = str[j];
}

/**
 * flag_right - function that checks for specifier
 *
 * @arg: argument
 * @buffer: array of string containing integer
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string.
 * @i:pointer to number of character
 *
 * Return: 2 on success
 */
int flag_right(va_list arg, char *buffer, const char *format, int n, int *i)
{
	int z;
	char h;

	if (format[n] == '*')
		z = va_arg(arg, int);
	else
		z = format[n] - '0';
	h = format[n + 1];
	if ((format[n + 1] == 'd' || format[n + 1] == 'i') ||
	    (format[n + 1] == 'u' || format[n + 1] == 'c'))
		flag_right_diuc(arg, buffer, i, z, h);
	if (format[n + 1] == 'o')
		flag_right_o(arg, buffer, i, z);
	if (format[n + 1] == 'x' || format[n + 1] == 'X')
		flag_right_xX(arg, buffer, i, z, h);
	if (format[n + 1] == 's')
		flag_right_s(arg, buffer, i, z);
	return (1);
}
