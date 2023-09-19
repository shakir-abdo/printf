#include "main.h"

/**
 * _printf - selects the correct function to print based on format specifiers.
 * @format: The format string to parse.
 * Return: The length of the string.
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%%", printf_37},
		{"%s", printf_string}, {"%c", printf_char},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_hex_2},
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto end_loop;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}

end_loop:
	va_end(args);
	return (len);
}

