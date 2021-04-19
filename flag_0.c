#include "holberton.h"

/**
 * flag_0o - function that prints octal with 0 flag.
 *
 * @m: number to print.
 * @buffer: values stored.
 * @i: pointer to index.
 */
void flag_0o(int m, char *buffer, int *i)
{
	int x;
	char *octvalues;
	char *oct;

	octvalues = "0123456789ABCDEF";

	oct = malloc(12 * sizeof(char));
	if (oct == NULL)
		return;
	if (m == 0)
	{
		buffer[*i] = '0';
		*i += 1;
	}
	for (x = 0; m != 0; x++)
	{
		oct[x] = octvalues[m % 8];
		m /= 8;
	}
	for (x--; x >= 0; *i += 1, x--)
	{
		buffer[*i] = oct[x];
	}
	free(oct);
}

/**
 * flag_0x - function that prints hexa with 0 flag
 *
 * @m: number to print
 * @buffer: values stored
 * @i: pointer to index
 * @k: 0 printed
 * @l: length to print
 */
void flag_0x(int m, char *buffer, int *i, int k, int l)
{
	int x, count = 0;
	char *hexvalues;
	char *hex;

	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	if (m == 0)
		hex[l] = '0';
	for (x = 0; m != 0; x++, count++)
	{
		hex[x] = hexvalues[m % 16];
		m /= 16;
	}
	if (k + count < l)
	{
		for (k = l - (k + count); k > 0; k--)
		{
			buffer[*i] = '0';
			*i += 1;
		}
	}
	for (x--; x >= 0; *i += 1, x--)
	{
		buffer[*i] = hex[x];
	}
	free(hex);
}

/**
 * flag_0X - function that prints hexa with 0 flag
 *
 * @m: number to print
 * @buffer: values stored
 * @i: pointer to index
 * @k: 0 printed
 * @l: length to print
 */
void flag_0X(int m, char *buffer, int *i, int k, int l)
{
	int x, count = 0;
	char *hexvalues;
	char *hex;

	hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	if (m == 0)
		hex[l] = '0';
	for (x = 0; m != 0; x++, count++)
	{
		hex[x] = hexvalues[m % 16];
		m /= 16;
	}
	if (k + count < l)
	{
		for (k = l - (k + count); k > 0; k--)
		{
			buffer[*i] = '0';
			*i += 1;
		}
	}
	for (x--; x >= 0; *i += 1, x--)
	{
		buffer[*i] = hex[x];
	}
	free(hex);
}

/**
 * flag_0 - function that prints with 0 flag
 *
 * @arg: argument passed in
 * @buffer: values stored
 * @format: String composed of zero ot more characters to print
 * @n: count of format
 * @i: returns pointer to index
 *
 * Return: 0 on success
 */
int flag_0(va_list arg, char *buffer, const char *format, int n, int *i)
{
	int x, len, k, m, l;
	char *c;

	m = va_arg(arg, int);
	k = m;
	x = format[n + 1] - '0';
	for (len = 0;  k != 0; len++)
		k /= 10;
	if (m <= 0)
		len++;
	if (x > len)
	{
		if (m < 0)
		{
			buffer[*i] = '-';
			*i += 1;
			m = -m;
		}
		k = x - len;
		l = x;
		for (x = x - len; x > 0; x--, *i += 1)
			buffer[*i] = '0';
	}
	c = malloc(sizeof(char) * len);
	if ((format[n + 2] == 'i' || format[n + 2] == 'd') || format[n + 2] == 'u')
	{
		itos(c, m);
		for (x = 0; c[x] != '\0'; c++, *i += 1)
		{
			buffer[*i] = c[x];
		}
	}
	if (format[n + 2] == 'o')
		flag_0o(m, buffer, i);
	if (format[n + 2] == 'x')
		flag_0x(m, buffer, i, k, l);
	if (format[n + 2] == 'X')
		flag_0X(m, buffer, i, k, l);
	return (2);
}
