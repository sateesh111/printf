#include "holberton.h"
/**
 * format_r - reverse a string passed in
 *
 * @arg: argument passed in
 * @buffer: values stored
 * @i: returns pointer to index
 *
 * Return: 0 on success
 */
int format_r(va_list arg, char *buffer, int *i)
{
	int n, strlen;
	char *s;

	s = va_arg(arg, char*);
	strlen = _strlen(s) - 1;
	if (s == NULL)
	{
		s = "(null)";
	}
	for (n = strlen; n >= 0; n--, *i += 1)
	{
		buffer[*i] = s[n];
	}
	return (0);
}

/**
 * format_R - functtion that converts a string into rot13
 * @arg: argument passed
 * @buffer: values stored
 * @i: tracks index position
 *
 * Return: 0 on success
 */
int format_R(va_list arg, char *buffer, int *i)
{
	char *s, *s1, *s2;
	int k, j;

	s = va_arg(arg, char*);
	s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";
	s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";

	for (k = 0; s[k] != '\0'; k++, *i += 1)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[k] == s1[j])
				buffer[*i] = s2[j];
			else if (s[k] == s2[j])
				buffer[*i] = s1[j];
		}
	}
	return (0);
}

/**
 * format_S - functtion that prints hex values of  0<ASCII value<32 or >=127
 *
 * @arg: argument passed
 * @buffer: values stored
 * @i: tracks index position
 *
 * Return: 0 on success
 */
int format_S(va_list arg, char *buffer, int *i)
{
	char *str, *hexvalues, *hex;
	int k, l, len = 0, m;

	str = va_arg(arg, char *);
	hexvalues = "0123456789ABCDEF";
	hex = malloc(2 * sizeof(char));

	for (k = 0; str[k] != 0; k++, *i += 1)
	{
		if ((str[k] > 0 && str[k] < 32) || str[k] >= 127)
		{
			m = str[k];
			for (l = 0, len = 0; m != 0; l++, len++)
			{
				hex[l] = hexvalues[m % 16];
				m /= 16;
			}
			buffer[*i] = '\\';
			*i += 1;
			buffer[*i] = 'x';
			*i += 1;
			if (len == 1)
			{
				buffer[*i] = '0';
				*i += 1;
				buffer[*i] = hex[len - 1];
			}
			else
			{
				buffer[*i] = hex[len - 1];
				*i += 1;
				buffer[*i] = hex[len - 2];
			}
		}
		else
			buffer[*i] = str[k];
	}
	free(hex);
	return (0);
}
