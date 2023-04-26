#include "main.h"

/**
  * get_length_modifier - gets the length_modifier
  * @format: control string
  *
  * Return: the modifier
  */

int get_length_modifier(const char *format)
{
	const char *ptr;
	int length_modifier = 0;

	ptr = format;
	while (*ptr)
	{
		if (*ptr == 'h' || *ptr == 'l')
		{
			if (*(ptr + 1) == *ptr)
			{
				length_modifier = *ptr == 'h' ? 1 : 2;
				break;
			}
			else
			{
				length_modifier = *ptr == 'h' ? 1 : 2;
			}
		}
		++ptr;
	}

	return (length_modifier);
}
