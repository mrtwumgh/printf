#include "main.h"

/**
  * get_func - gets the right function
  * @sp: specifier
  *
  * Return: the function
  */

int (*get_func(char sp))(char *, va_list, int, int, int, int, int)
{
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i;

	for (i = 0; specs[i].spec != '\0'; i++)
	{
		if (specs[i].spec == sp)
		{
			return (specs[i].func);
		}
	}

	return (NULL);
}
