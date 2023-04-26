#include "main.h"

/**
  * print_char - prints a character
  * @buffer: buffer
  * @list: variable arguments
  * @index: index of buffer
  * @width: unused
  * @precision: unused
  * @length_modifier: unused
  * @flags: unused
  *
  * Return: 1
  */

int print_char(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags)
{
	char c;
	(void)width;
	(void)precision;
	(void)length_modifier;
	(void)flags;

	c = va_arg(list, int);

	buffer[index++] = c;

	return (index);
}
