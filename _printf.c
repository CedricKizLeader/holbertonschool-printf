#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char nextchar;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')

			nextchar = *(format + 1);
		if (nextchar == 'c')
			count += print_char(args);
		if (nextchar == '%')
			count += print_pourcent(args);
		if (nextchar == 's')
			count += print_string(args);

		format += 1;

		_putchar(*format);
		count++;
	}
	format++;


	va_end(args);
	return (count);
}
