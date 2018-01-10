#include "ft_printf.h"

size_t	ft_process_flag(const char *format, va_list vlst)
{
	int i;

	i = 0;
	if (*format == 's')
		i = ft_putstr(va_arg(vlst, char*));
	else if (*format == 'd' || *format == 'i')
		i = ft_putnbr(va_arg(vlst, int));
	else if (*format == 'u')
		i = ft_putunbr(va_arg(vlst, unsigned int));
	else if (*format == '%')
		i = ft_putchar('%');
	else if (*format == 'c')
		i = ft_putchar((char)va_arg(vlst, char*));
	else if (*format == 'x')
		i = ft_putnbr_hex(va_arg(vlst, unsigned int), 0);
	else if (*format == 'o')
		i = ft_putnbr_oct(va_arg(vlst, unsigned int), 0);
	else if (*format == 'X')
		i = ft_putnbr_mhex(va_arg(vlst, unsigned int), 0);
	else if (*format == 'S')
		i = ft_putwstr(va_arg(vlst, wchar_t*));
	else if (*format == 'C')
		i = ft_putwchar((wchar_t)va_arg(vlst, wchar_t*));
	else if (*format == 'p')
		i = ft_putnbr_lhex(va_arg(vlst, long int));
	else if (*format == 'D')
		i = ft_putnbr_l(va_arg(vlst, long int));
	else if (*format == 'O')
		i = ft_putnbr_loct(va_arg(vlst,unsigned long int), 0);
	else if (*format == 'U')
		i = ft_putunbr_l(va_arg(vlst, unsigned long int));
	else
		return (-1);
	return (i);
}