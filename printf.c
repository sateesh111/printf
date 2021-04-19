#include "holberton.h"

/**
 *func_sp -function that contains specifiers and corresponding arguments.
 *
 *@arg: list of argument.
 *@buffer: array of string containing integer.
 *@format:String composed of zero ot more characters to print
 *@n: Integers that contains the index of the string.
 *@i:pointer to number of character.
 *
 * Return: 1 on success
 */
int func_sp(va_list arg, char *buffer, const char *format, int n, int *i)
{
	int j, k = 0;

	vtype_t specifier[] = {
		{'c', format_c}, {'s', format_str},
		{'%', format_pers}, {'d', format_d},
		{'i', format_d}, {'p', format_p}, {'u', format_u},
		{'o', format_o}, {'x', format_x}, {'X', format_X},
		{'r', format_r}, {'R', format_R}, {'S', format_S},
		{'b', format_b}, {'+', flag_plus}, {' ', flag_spc},
		{'#', flag_hash}, {'0', flag_0}, {'-', flag_left},
		{'.', precision}};

	for (j = 0; specifier[j].sp != '\0'; j++)
	{
		if ((format[n] > '0' && format[n] <= '9') || format[n] == '*')
		{
			k = flag_right(arg, buffer, format, n, i);
			break;
		}
		if (specifier[j + 1].sp == '\0' && specifier[j].sp != '0')
		{
			buffer[*i] = format[n - 1];
			*i += 1;
			buffer[*i] = format[n];
			*i += 1;
		}
		if (format[n] == specifier[j].sp)
		{
			if ((format[n] == ' ' || format[n] == '#') ||
			    (format[n] == '0' || format[n] == '-') ||
			    (format[n] == '.'))
				k = specifier[j].fo(arg, buffer, format, n, i);
			else
				k = specifier[j].fo(arg, buffer, i);
			break;
		}
	}
	return (k);
}

/**
 * _printf - function that prints according to a format
 *
 * @format: String composed of zero ot more characters to print
 *
 * Return: i, number of character printed
 */
int _printf(const char *format, ...)
{
	char *buffer;
	int n, x = 0, *i = &x;
	va_list arg;

	buffer = malloc(2048 * sizeof(char));
	if (buffer == NULL)
		return (-1);
	if (!format)
		return (free(buffer), -1);
	va_start(arg, format);
	for (n = 0; format[n] != '\0'; n++)
	{
		for (; format[n] != '%' && format[n] != '\0'; *i += 1, n++)
		{
			buffer[*i] = format[n];
		}
		if (format[n] == '\0')
			break;
		if (format[n] == '%' && format[n + 1] == '\0')
			return (-1);
		if (format[n] == '%' && format[n + 1] != '\0')
		{
			n++;
			n += func_sp(arg, buffer, format, n, i);
		}
	}
	va_end(arg);
	buffer[*i] = '\0';
	_putchar(buffer, i);
	free(buffer);
	return (*i);
}
