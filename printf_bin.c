#include "main.h"

/**
 * printf_bin - Prints a binary number.
 * @val: Arguments containing the number to print.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int printf_bin(va_list val)
{
	int count = 0;
	int flag = 0;
	int i, a = 1, b;
	unsigned int p;
	unsigned int num = va_arg(val, unsigned int);

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + '0');
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}

