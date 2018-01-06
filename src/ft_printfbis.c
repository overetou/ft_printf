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

size_t	ft_process_flag(const char *format, va_list vlst)
{
	int i;

	i = 0;
	if (*format == 's')
		i = ft_putstr(va_arg(vlst, char*));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(vlst, int));
	else if (*format == 'u')
		ft_putunbr(va_arg(vlst, unsigned int));
	else if (*format == 'c')
		ft_putchar((char)va_arg(vlst, char*));
	else if (*format == 'x')
		ft_putnbr_hex(va_arg(vlst, unsigned int));
	else if (*format == 'o')
		ft_putnbr_oct(va_arg(vlst, unsigned int));
	else if (*format == 'X')
		ft_putnbr_mhex(va_arg(vlst, unsigned int));
	else if (*format == 'C')
		ft_putwchar((wchar_t)va_arg(vlst, wchar_t*));
	else if (*format == 'S')
		ft_putwstr(va_arg(vlst, wchar_t*));
	else
	{
		if (*(++format))
			return (ft_process_flag(format, vlst));
		return (-1);
	}
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
				i += ft_process_flag(format++, vlst);
		}
	}
	va_end(vlst);
	return (i);
}
