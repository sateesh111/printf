#include "holberton.h"

/**
 * hash_o - Function that prints 0 before octal value.
 *
 * @arg: list of argument.
 * @buffer: array that stores string
 * @i: pointer to number of character
 */
void hash_o(va_list arg, char *buffer, int *i)
{
	unsigned int k;
	int x;
	char *octvalues;
	char *oct;

	k = va_arg(arg, int);
	octvalues = "0123456789ABCDEF";

	oct = malloc(12 * sizeof(char));
	if (oct == NULL)
		return;
	if (k == 0)
	{
		oct[0] = '0';
		buffer[*i] = oct[0];
		*i += 1;
		buffer[*i] = oct[0];
		*i += 1;
	}
	if (k != 0)
	{
		for (x = 0; k != 0; x++)
		{
			oct[x] = octvalues[k % 8];
			k /= 8;
		}
		oct[x] = '0';
		for (; x >= 0; *i += 1, x--)
		{
			buffer[*i] = oct[x];
		}
	}
	free(oct);
}

/**
 * hash_x - Function that prints 0x before hexa value
 *
 * @arg: list of argument
 * @buffer: array that stores string
 * @i: pointer to number of character
 */
void hash_x(va_list arg, char *buffer, int *i)
{
	unsigned int n;
	int x;
	char *hexvalues;
	char *hex;

	n = va_arg(arg, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	if (n == 0)
	{
		hex[0] = '0';
		buffer[*i] = hex[0];
		*i += 1;
		buffer[*i] = hex[0];
		*i += 1;
	}
	if (n != 0)
	{
		for (x = 0; n != 0; x++)
		{
			hex[x] = hexvalues[n % 16];
			n /= 16;
		}
		hex[x] = 'x';
		x++;
		hex[x] = '0';
		for (; x >= 0; *i += 1, x--)
		{
			buffer[*i] = hex[x];
		}
	}
	free(hex);
}

/**
 * hash_X - Function that prints 0X before hexa value
 *
 * @arg: list of argument
 * @buffer: array that stores string
 * @i: pointer to number of character
 */
void hash_X(va_list arg, char *buffer, int *i)
{
	unsigned int n;
	int x;
	char *hexvalues;
	char *hex;

	n = va_arg(arg, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	if (n == 0)
	{
		hex[0] = '0';
		buffer[*i] = hex[0];
		*i += 1;
		buffer[*i] = hex[0];
		*i += 1;
	}
	if (n != 0)
	{
		for (x = 0; n != 0; x++)
		{
			hex[x] = hexvalues[n % 16];
			n /= 16;
		}
		hex[x] = 'X';
		x++;
		hex[x] = '0';
		for (; x >= 0; *i += 1, x--)
		{
			buffer[*i] = hex[x];
		}
	}
	free(hex);
}

/**
 * flag_hash - function that checks for octal or hexa
 *
 * @arg: list of argument.
 * @buffer: array of string containing integer.
 * @format:String composed of zero ot more characters to print
 * @n: Integers that contains the index of the string.
 * @i:pointer to number of character.
 *
 * Return: 1 0n success
 */
int flag_hash(va_list arg, char *buffer, const char *format, int n, int *i)
{
	if (format[n + 1] == 'o')
		hash_o(arg, buffer, i);
	if (format[n + 1] == 'x')
		hash_x(arg, buffer, i);
	if (format[n + 1] == 'X')
		hash_X(arg, buffer, i);
	return (1);
}
