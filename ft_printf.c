#include "ft_printf.h"
#include <stdarg.h>

const char	*ft_print_until_flag(const char *format)
{
	while (*format != '%' && *format)
		ft_putchar(*format++);
	return (format);
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
	return (format + x);
}

int	ft_printf(char const *format, ...)
{
	va_list	vlst;

	va_start(vlst, format);
	while (*format)
	{
		format = ft_print_until_flag(format);
		if (*format)
		{
			if (*(++format) == '%')
			{
				ft_putchar('%');
				format++;
			}
			else
				format = ft_process_flag(format, vlst);
		}
	}
	va_end(vlst);
	return (0);
}
