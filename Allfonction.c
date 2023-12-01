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
        {
            nextchar = *(format + 1);
            if (nextchar == 'c')
                count += print_char(args);
            else if (nextchar == '%')
                count += print_percent(args);
            else if (nextchar == 's')
                count += print_string(args);
            else if (nextchar == 'd' || nextchar == 'i')
                count += print_int(args);
            else
                _putchar(*format); // Si le format n'est pas reconnu, imprime le caractère '%' tel quel
            format += 2; // Avance de deux caractères (%c, %s, %%)
        }
        else
        {
            _putchar(*format);
            count++;
            format++;
        }
    }

    va_end(args);
    return count;
}

