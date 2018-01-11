#include "ft_printf.h"

char	ft_find_conv(const char *format)
{
	while (*format && *format != 's' && *format != 'd' && *format != 'i' && *format != 'u'
		&& *format != '%' && *format != 'c' && *format != 'x' && *format != 'o'
		&& *format != 'X' && *format != 'S' && *format != 'S' && *format != 'S'
		&& *format != 'C' && *format != 'p' && *format != 'D' && *format != 'O'
		&& *format != 'U')
		format++;
	return (*format);
}

int	ft_process_conv(char conv, va_list vlst, int to_print)
{
	int i;

	i = 0;
	if (conv == 's')
		i = ft_putstr(va_arg(vlst, char*));
	else if (conv == 'd' || conv == 'i')
		i = ft_putnbr(va_arg(vlst, int));
	else if (conv == 'u')
		i = ft_putunbr(va_arg(vlst, unsigned int));
	else if (conv == '%')
		i = ft_putchar('%');
	else if (conv == 'c')
		i = ft_putchar((char)va_arg(vlst, char*));
	else if (conv == 'x')
		i = ft_putnbr_hex(va_arg(vlst, unsigned int), to_print);
	else if (conv == 'o')
		i = ft_putnbr_oct(va_arg(vlst, unsigned int), to_print);
	else if (conv == 'X')
		i = ft_putnbr_mhex(va_arg(vlst, unsigned int), to_print);
	else if (conv == 'S')
		i = ft_putwstr(va_arg(vlst, wchar_t*));
	else if (conv == 'C')
		i = ft_putwchar((wchar_t)va_arg(vlst, wchar_t*));
	else if (conv == 'p')
		i = ft_putnbr_lhex(va_arg(vlst, long int));
	else if (conv == 'D')
		i = ft_putnbr_l(va_arg(vlst, long int));
	else if (conv == 'O')
		i = ft_putnbr_loct(va_arg(vlst,unsigned long int), to_print);
	else if (conv == 'U')
		i = ft_putunbr_l(va_arg(vlst, unsigned long int));
	else
		return (-1);
	return (i);
}

int		ft_process_htag(const char **format, char *padding, char conv, int *to_print)
{
	int i;

	i = 0;
	(void)*padding;
	if (**format == conv)
		return (i);
	if (**format == '#')
	{
		if (conv == 'o' || conv == 'O')
			i += ft_putchar('0');
		(*format)++;
		*to_print = 0;
	}
	return (i);
}

int		ft_process_flag(const char **format, va_list vlst)
{
	int		i;
	char	conv;
	char	padding;
	int		to_print;

	padding = ' ';
	(*format)++;
	to_print = -1;
	if ((conv = ft_find_conv(*format)) == 0)
		return (0);
	i = ft_process_htag(format, &padding, conv, &to_print);
	i += ft_process_conv(conv, vlst, to_print);
	return (i);
}