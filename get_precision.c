#include "main.h"

/**
  * get_precision - gets the precision
  * @format: control string
  * @list: variable arguments
  *
  * Return: the precision
  */

int get_precision(const char *format, va_list list)
{
	int precision = -1;

	while (format && *format != '\0')
	{
		if (*format == '.')
		{
			++format;
			if (*format == '*')
			{
				precision = va_arg(list, int);
			}
			else
			{
				precision = 0;
				while (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
					++format;
				}
				--format;
			}
			break;
		}
		++format;
	}

	return (precision);
}
