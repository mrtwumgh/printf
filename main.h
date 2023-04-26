#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FLAG_MINUS 1
#define FLAG_ZERO 2
/**
  * struct specifier - struct
  * @func: function pointer
  * @spec: specifier
  */

typedef struct specifier
{
	char spec;
	int (*func)(char *, va_list, int, int, int, int, int);
} spec_t;

int (*get_func(char sp))(char *, va_list, int, int, int, int, int);

int _printf(const char *format, ...);

int get_field_width(const char *format, va_list list);
int get_precision(const char *format, va_list list);
int get_length_modifier(const char *format);
int get_flags(const char *format);

int print_char(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_string(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_percent(char  *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_int(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_unsigned(char *buffer, va_list list, int index,
		int width, int precision, int length_modifier, int flags);
int print_octal(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_hex(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_HEX(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_pointer(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_binary(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_np(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);

int print_r(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);
int print_R(char *buffer, va_list list, int index, int width,
		int precision, int length_modifier, int flags);

#endif /* MAIN_H */
