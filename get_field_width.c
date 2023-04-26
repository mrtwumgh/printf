#include "main.h"

/**
  * get_field_width - gets the width fromm the string
  * @format: the control string
  * @list: variable arguments
  *
  * Return: width
  */

int get_field_width(const char *format, va_list list)
{
	int width = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] && (format[i] == '-' || format[i] == '+' ||
					     format[i] == ' ' || format[i] == '0' ||
					     format[i] == '#' || format[i] == '*' ||
					     (format[i] >= '0' && format[i] <= '9') ||
					     format[i] == '.' || format[i] == 'h' ||
					     format[i] == 'l'))
			{
				i++;
			}
			if (format[i] >= '1' && format[i] <= '9')
			{
				width = atoi(&format[i]);
				break;
			}
			else if (format[i] == '*')
			{
				width = va_arg(list, int);
				break;
			}
		}
		i++;
	}

	return ((width > 0 ? width : -1));
}
