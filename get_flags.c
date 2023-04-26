#include "main.h"

/**
  * get_flags - return the flags
  * @format: control string
  *
  * Return: integer representing the flags
  */

int get_flags(const char *format)
{
	int flags = 0;

	while (*format)
	{
		switch (*format)
		{
			case '-':
				flags |= 1 << 0;
				break;
			case '+':
				flags |= 1 << 1;
				break;
			case ' ':
				flags |= 1 << 2;
				break;
			case '#':
				flags |= 1 << 3;
				break;
			case '0':
				flags |= 1 << 4;
				break;
			default:
				return (flags);
		}
		format++;
	}

	return (flags);
}
