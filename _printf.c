#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters printed *
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int num_chars_printed = 0;

	while (format != '\0')
	{
		if (format == '%')
		{
			format++;
			switch (format)
			{
				case 'c':
					putchar(va_arg(args, int));
					num_chars_printed++;
					break;
				case 's':
					num_chars_printed += printf("%s", va_arg(args, char));
					break;
				default:
					printf("Unknown format specifier: %c", format);
			}
		}
		else
		{
			putchar(*format);
			num_chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (num_chars_printed);
}
