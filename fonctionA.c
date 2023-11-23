#include <main.h>

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string containing directives
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's')
        {
            char *str = va_arg(args, char *);
            str = (str == NULL) ? "(null)" : str;
            while (*str)
                count += putchar(*str++);
            format += 2;
        }
        else
        {
            count += putchar(*format++);
        }
    }

    va_end(args);
    return count;
}

