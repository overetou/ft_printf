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

const char	*ft_process_flag(const char *format, va_list vlst)
{
	unsigned int	x;

	x = 1;
	if (*format == 's')
		ft_putstr(va_arg(vlst, char*));
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
	return (format + x);
}

int	ft_printf(char const *format, ...)
{
	va_list	vlst;
	size_t i;

	va_start(vlst, format);
	i = 0;
	while (format[i])
	{
		i = ft_print_until_flag(format);
		if (format[i])
		{
			if (format[++i] == '%')
			{
				ft_putchar('%');
				format++;
			}
			else
				format = ft_process_flag(format, vlst);
		}
	}
	va_end(vlst);
	return (i);
}
