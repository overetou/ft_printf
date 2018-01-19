/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:34:34 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:34:36 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>
#include <unistd.h>

static int	ft_sort_di(char *flags, va_list vlst)
{
	if (ft_count(flags, 'h') == 1)
		return (ft_putnbr_printf((short)va_arg(vlst, int), flags));
	else if (ft_count(flags, 'h') == 2)
		return (ft_putnbr_printf((signed char)va_arg(vlst, int), flags));
	else if (ft_count(flags, 'z'))
		return (ft_putnbr_l((size_t)va_arg(vlst, intmax_t), flags));
	else if (ft_count(flags, 'l') == 1)
		return (ft_putnbr_l((long int)va_arg(vlst, intmax_t), flags));
	else if (ft_count(flags, 'l') == 2)
		return (ft_putnbr_l((long long int)va_arg(vlst, intmax_t), flags));
	else if (ft_detect(flags, 'j'))
		return (ft_putnbr_l(va_arg(vlst, intmax_t), flags));
	else
		return (ft_putnbr_printf(va_arg(vlst, int), flags));
}

static int ft_sort_u(char *flags, va_list vlst)
{
	if (ft_count(flags, 'h') == 1)
		return (ft_putunbr((unsigned short)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'h') == 2)
		return (ft_putunbr((unsigned char)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'z'))
		return (ft_putunbr_l((size_t)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 1)
		return (ft_putunbr_l((unsigned long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 2)
		return (ft_putunbr_l((unsigned long long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_detect(flags, 'j'))
		return (ft_putunbr_l(va_arg(vlst, uintmax_t), flags));
	else
		return (ft_putunbr(va_arg(vlst, unsigned int), flags));
}

static int ft_sort_o(char *flags, va_list vlst)
{
	if (ft_count(flags, 'h') == 1)
		return (ft_putnbr_oct((unsigned short)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'h') == 2)
		return (ft_putnbr_oct((unsigned char)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'z'))
		return (ft_putnbr_loct((size_t)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 1)
		return (ft_putnbr_loct((unsigned long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 2)
		return (ft_putnbr_loct((unsigned long long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_detect(flags, 'j'))
		return (ft_putnbr_loct(va_arg(vlst, uintmax_t), flags));
	else
		return (ft_putnbr_oct(va_arg(vlst, unsigned int), flags));
}

static int ft_sort_x(char *flags, va_list vlst)
{
	if (ft_count(flags, 'h') == 1)
		return (ft_putnbr_hex((unsigned short)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'h') == 2)
		return (ft_putnbr_hex((unsigned char)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'z'))
		return (ft_putnbr_lhex((size_t)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 1)
		return (ft_putnbr_lhex((unsigned long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 2)
		return (ft_putnbr_lhex((unsigned long long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_detect(flags, 'j'))
		return (ft_putnbr_lhex(va_arg(vlst, uintmax_t), flags));
	else
		return (ft_putnbr_hex(va_arg(vlst, unsigned int), flags));
}

static int ft_sort_X(char *flags, va_list vlst)
{
	if (ft_count(flags, 'h') == 1)
		return (ft_putnbr_mhex((unsigned short)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'h') == 2)
		return (ft_putnbr_mhex((unsigned char)va_arg(vlst, unsigned int), flags));
	else if (ft_count(flags, 'z'))
		return (ft_putnbr_mlhex((size_t)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 1)
		return (ft_putnbr_mlhex((unsigned long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_count(flags, 'l') == 2)
		return (ft_putnbr_mlhex((unsigned long long int)va_arg(vlst, uintmax_t), flags));
	else if (ft_detect(flags, 'j'))
		return (ft_putnbr_mlhex(va_arg(vlst, uintmax_t), flags));
	else
		return (ft_putnbr_mhex(va_arg(vlst, unsigned int), flags));
}

static int ft_sort_c(char *flags, va_list vlst)
{
	if (ft_detect(flags, 'l'))
		return (ft_putwchar(va_arg(vlst, long int)));
	return (ft_putchar_printf(va_arg(vlst, int), flags));
}

static int ft_sort_s(char *flags, va_list vlst)
{
	if (ft_detect(flags, 'l'))
		return (ft_putwstr_printf(va_arg(vlst, char*), flags));
	return (ft_putstr_printf(va_arg(vlst, char*), flags));
}
static char	ft_find_conv(const char *format)
{
	while (*format && *format != 's' && *format != 'd' && *format != 'i' && *format != 'u'
	&& *format != '%' && *format != 'c' && *format != 'x' && *format != 'o'
	&& *format != 'X' && *format != 'S' && *format != 'S' && *format != 'S'
	&& *format != 'C' && *format != 'p' && *format != 'D' && *format != 'O'
	&& *format != 'U')
	{
		if (*format != '+' && *format != '-' && *format != ' ' && *format != '#' && *format != 'l'
		&& *format != 'h' && *format != 'z' && *format != 'j' && *format != '0' && (*format < '0'
		|| *format > '9') && *format != '.')
			return (*format);
		format++;	
	}
	return (*format);
}

static char	*ft_find_flags(const char **format, char conv)
{
	char *new;

	new = ft_strnew(0);
	while (**format != conv)
	{
		new = ft_addchar(&new, **format);
		(*format)++;
	}
	return (new);
}

int	ft_process_conv(char conv, va_list vlst, char *flags)
{
	int i;

	i = 0;
	if (conv == 's')
		i = ft_sort_s(flags, vlst);
	else if (conv == 'd' || conv == 'i')
		i = ft_sort_di(flags, vlst);
	else if (conv == 'u')
		i = ft_sort_u(flags, vlst);
	else if (conv == '%')
		i = ft_putpercent(flags);
	else if (conv == 'c')
		i = ft_sort_c(flags, vlst);
	else if (conv == 'x')
		i = ft_sort_x(flags, vlst);
	else if (conv == 'o')
		i = ft_sort_o(flags, vlst);
	else if (conv == 'X')
		i = ft_sort_X(flags, vlst);
	else if (conv == 'S')
		i = ft_putwstr_printf(va_arg(vlst, char*), flags);
	else if (conv == 'C')
		i = ft_putwchar((wchar_t)va_arg(vlst, wchar_t*));
	else if (conv == 'p')
		i = ft_putnbr_p(va_arg(vlst, unsigned long int), flags);
	else if (conv == 'D')
		i = ft_putnbr_l(va_arg(vlst, long int), flags);
	else if (conv == 'O')
		i = ft_putnbr_loct(va_arg(vlst,unsigned long int), flags);
	else if (conv == 'U')
		i = ft_putunbr_l(va_arg(vlst, unsigned long int), flags);
	else
		return (-1);
	return (i);
}

int		ft_process_flag(const char **format, va_list vlst)
{
	char	conv;
	char	*flags;
	int 	ret;

	(*format)++;
	conv = ft_find_conv(*format);
	if (conv == '\0')
	{
		while (**format == '+' || **format == '-' || **format == ' ' || **format == '#' || **format == 'l'
		|| **format == 'h' || **format == 'z' || **format == 'j' || **format == '0' || (**format >= '0'
		&& **format <= '9') || **format == '.')
			(*format)++;
		return (-1);
	}
	flags = ft_find_flags(format, conv);
	ret = ft_process_conv(conv, vlst, flags);
	ft_strdel(&flags);
	return (ret);
}
