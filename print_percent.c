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

int print_percent(char *buffer, va_list list, int index, int width,
			int precision, int length_modifier, int flags)
{
	(void)list;
	(void)width;
	(void)precision;
	(void)length_modifier;
	(void)flags;

	buffer[index] = '%';

	return (1);
}
