#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function
 * @format: format
 * Return: returns printed characters
 */
int _printf(const char *format, ...)
{
int ruto, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);

va_start(list, format);

for (ruto = 0; format && format[ruto] != '\0'; ruto++)
{
if (format[ruto] != '%')
{
buffer[buff_ind++] = format[ruto];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);

printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &ruto);
width = get_width(format, &ruto, list);
precision = get_precision(format, &ruto, list);
size = get_size(format, &ruto);
++ruto;
printed = handle_print(format, &ruto, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

/**
 * print_buffer - Prints the buffer contents
 * @buffer: array of characters
 * @buff_ind: index to add next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}

