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

char	*ft_find_flags(const char **format, char conv)
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
		i = ft_putstr(va_arg(vlst, char*));
	else if (conv == 'd' || conv == 'i')
		i = ft_putnbr_printf(va_arg(vlst, int), flags);
	else if (conv == 'u')
		i = ft_putunbr(va_arg(vlst, unsigned int));
	else if (conv == '%')
		i = ft_putpercent(flags);
	else if (conv == 'c')
		i = ft_putchar((char)va_arg(vlst, char*));
	else if (conv == 'x')
		i = ft_putnbr_hex(va_arg(vlst, unsigned int), flags);
	else if (conv == 'o')
		i = ft_putnbr_oct(va_arg(vlst, unsigned int), flags);
	else if (conv == 'X')
		i = ft_putnbr_mhex(va_arg(vlst, unsigned int), flags);
	else if (conv == 'S')
		i = ft_putwstr(va_arg(vlst, wchar_t*));
	else if (conv == 'C')
		i = ft_putwchar((wchar_t)va_arg(vlst, wchar_t*));
	else if (conv == 'p')
		i = ft_putnbr_lhex(va_arg(vlst, long int));
	else if (conv == 'D')
		i = ft_putnbr_l(va_arg(vlst, long int));
	else if (conv == 'O')
		i = ft_putnbr_loct(va_arg(vlst,unsigned long int), flags);
	else if (conv == 'U')
		i = ft_putunbr_l(va_arg(vlst, unsigned long int));
	else
		return (-1);
	ft_strdel(&flags);
	return (i);
}

int		ft_process_flag(const char **format, va_list vlst)
{
	char	conv;
	char	*flags;

	(*format)++;
	conv = ft_find_conv(*format);
	if (conv == 0)
		return (0);
	flags = ft_find_flags(format, conv);
	return (ft_process_conv(conv, vlst, flags));
}
