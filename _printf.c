#include "main.h"

/**
  * _printf - prints out formatted output
  * @format: control string
  *
  * Return: the number of arguments
  */

int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFFER_SIZE] = {0};
	int i = 0, j = 0, count = 0;
	spec_t spec = {0};
	int width, precision, length_modifier, flags;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			spec.func = get_func(format[i]);
			spec.spec = format[i];
			if (spec.func == NULL)
			{
				if (j == BUFFER_SIZE)
				{
					write(1, buffer, j);
					count += j;
					j = 0;
				}
				buffer[j] = '%';
				j++;
				buffer[j] = format[i];
				j++;
			}
			else
			{
				width = get_field_width(format + i, list);
				precision = get_precision(format + i, list);
				length_modifier = get_length_modifier(format + i);
				flags = get_flags(format + i);
				j = spec.func(buffer, list, j, width, precision, length_modifier, flags);
			}
		}
		else
		{
			if (j == BUFFER_SIZE)
			{
				write(1, buffer, j);
				count += j;
				j = 0;
			}
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	if (j > 0)
	{
		write(1, buffer, j);
		count += j;
	}
	va_end(list);
	return (count);
}
