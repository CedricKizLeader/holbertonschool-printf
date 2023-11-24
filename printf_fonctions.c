#include "main.h"

int print_pourcent(va_list arguments)
{
	_putchar('%');

	return (1);
}

int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);

	return (_putchar(c));
}

int print_string(va_list arguments)
{
	char *string = va_arg(arguments, char *);
	char *null = "(null)";
	int length = 0;

	if (string == NULL)
	{
		return (write(1, null, 6));
	}

	while (*string != '\0')
	{
		_putchar(*string);
		string++;

		length++;
	}

	return (length);
}
