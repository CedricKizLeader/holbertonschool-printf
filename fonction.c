#include <main.h>

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string containing directives
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			char *str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			while (*str != '\0')
			{
				putchar(*str);
				count++;
				str++;
			}
			format += 2;
		}
		else
		{
			putchar(*format);
			count++;
			format++;
		}
	}

	va_end(args);
	return (count);
}
