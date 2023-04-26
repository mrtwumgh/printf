#include "main.h"

/**
  * print_int - prints a integer
  * @buffer: buffer
  * @list: variable arguments
  * @index: index of buffer
  * @width: width
  * @precision: precision
  * @length_modifier: length modifier
  * @flags: flags
  *
  * Return: index
  */

int print_int(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags)
{
	int num = 0, n = 0, neg = 0, i = 0;
	char temp[BUFFER_SIZE] = {0};

	switch (length_modifier)
	{
		case 1:
			num = (short)va_arg(list, int);
			break;
		case 2:
			num = va_arg(list, long);
			break;
		case 3:
			num = va_arg(list, size_t);
			break;
		default:
			num = va_arg(list, int);
	}
	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	do {
		temp[n++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	if (precision > n)
	{
		for (i = 0; i < precision - n; i++)
		{
			temp[n++] = '0';
		}
	}
	if (width > n + neg && !(flags & (1 << 0)))
	{
		for (i = 0; i < width - n - neg; i++)
		{
			buffer[index++] = ' ';
		}
	}
	if (neg)
	{
		buffer[index++] = '-';
	}
	else if (flags & (1 << 1))
	{
		buffer[index++] = '+';
	}
	else if (flags & (1 << 2))
	{
		buffer[index++] = ' ';
	}
	if (width > n + neg && flags & (1 << 0))
	{
		for (i = 0; i < width - n - neg; i++)
		{
			buffer[index++] = '0';
		}
	}
	while (n > 0)
	{
		buffer[index++] = temp[--n];
	}
	return (index);
}
