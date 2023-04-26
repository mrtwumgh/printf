#include "main.h"

/**
  * print_string - prints a string
  * @buffer: buffer
  * @list: variable arguments
  * @index: index of buffer
  * @width: width
  * @precision: precision
  * @length_modifier: unused
  * @flags: flags
  *
  * Return: the number of characters
  */

int print_string(char *buffer, va_list list, int index, int width,
			int precision, int length_modifier, int flags)
{
	char *s;
	int len = 0, padding = 0, i;
	(void)precision;
	(void)length_modifier;

	printf("width: %d\n", width);
	s = va_arg(list, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	len = strlen(s);
	if (width)
	{
		padding = len - width;
	}
	else
	{
		padding = len;
	}
	for (i = 0; i < padding; i++)
	{
		buffer[index++] = s[i];
	}

	if (flags & FLAG_MINUS)
	{
		for (i = 0; i < padding; i++)
		{
			buffer[index++] = ' ';
		}
	}
	printf("%s\n", buffer);

	return (index);
}
