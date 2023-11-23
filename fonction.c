#include <main.h> 

int _putchar(char c)
{
    return write(1, &c, 1);
}

int print_str(char *str)
{
    int count = 0;
    while (*str)
    {
        _putchar(*str);
        count++;
        str++;
    }
    return count;
}

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's')
        {
            char *str = va_arg(args, char *);
            if (str == NULL)
                str = "(null)";

            count += print_str(str);
            format += 2;
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
