#include "holberton.h"
#include <stdio.h>

/**
 * itos - Function to convert integer to string
 *
 * @str: array to store string.
 * @n: integer.
 *
 * Return: str
 */
char *itos(char str[], long int n)
{
	int i, temp, div, length, last;

	last = n % 10;
	i = 0;
	if (last < 0)
	{
		last *= -1;
		str[i] = '-';
		i++;
	}
	n = (n / 10);
	if (n < 0)
		n *= -1;

	if (str[0] == '+' || str[0] == ' ')
		i++;

	length = 0;
	div = 1;
	temp = n;
	while (temp > 0)
	{
		length += 1;
		div *= 10;
		temp = temp / 10;
	}
	div = div / 10;
	while (div >= 1)
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = last + '0';
	return (str);
}

/**
 * utos - Function to convert unsigned int to string
 *
 * @str: array to store string
 * @num: number to convert
 *
 * Return: str
 */
char *utos(char str[], unsigned int num)
{
	int i, rem, len = 0;
	unsigned int n;

	n = num;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	i = 0;

	while (i < len)
	{
		rem = num % 10;
		num = num / 10;

		str[len - (i + 1)] = rem + '0';
		i++;
	}

	str[len] = '\0';
	return (str);
}

/**
 * num_len - Function that counts the length of a number
 *
 * @num: number to count
 *
 * Return: len, length of number
 */
int num_len(unsigned int num)
{
	unsigned int n;
	int len;

	n = num;
	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * _strlen - Function to count the number of string
 *
 * @s: string to count
 *
 * Return: count, length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
