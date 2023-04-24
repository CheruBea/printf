#include "main.h"

/**
 * print_unsigned - unsigned number
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[a--] = (num % 10) + '0';
num /= 10;
}

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_octal - unsigned number in octal notation
 * @types: List of arguments
 * @buffer: array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[a--] = (num % 8) + '0';
num /= 8;
}

if (flags & F_HASH && init_num != 0)
buffer[a--] = '0';
a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - unsigned number in hexadecimal
 * @types: List of arguments
 * @buffer: array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/**
 * print_hexa - prints a hexadecimal number
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active character flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[a--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}
a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

