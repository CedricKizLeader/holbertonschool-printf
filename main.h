#ifndef PROTO
#define PROTO

#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _putchar(char character);

int print_char(va_list arguments);
int print_string(va_list arguments);
int print_pourcent(va_list arguments);

#endif
