#include "ft_printf.h"
#include <stdarg.h>

size_t	ft_print_until_flag(const char *format)
{
	size_t i;

	i = 0;
	while (format[i] != '%' && format[i])
		ft_putchar(format[i++]);
	return (i);
}

int		ft_printf(char const *format, ...)
{
	va_list	vlst;
	size_t s;
	size_t i;

	va_start(vlst, format);
	i = 0;
	while (*format)
	{
		s = ft_print_until_flag(format);
		format += s;
		i += s;
		if (*format)
		{
			if (*(++format) == '%')
			{
				ft_putchar('%');
				format++;
				i++;
			}
			else
				
				//i += ft_process_flag(format++, vlst);
		}
	}
	va_end(vlst);
	return (i);
}
