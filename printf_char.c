#include "main.h"

/**
 * printf_char - Prints a character.
 * @val: Arguments containing the character to print.
 *
 * Return: Number of characters printed (always 1).
 */
int printf_char(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
