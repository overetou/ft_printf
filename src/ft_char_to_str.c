/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:28:46 by overetou          #+#    #+#             */
/*   Updated: 2018/01/08 15:28:48 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_to_str(char c, int *sz)
{
	char *new;

	new = ft_strnew(1);
	*new = c;
	*sz = 1;
	return (new);
}

int		ft_sort_c(char *flags, va_list vlst)
{
	if (ft_detect(flags, 'l'))
		return (ft_putwchar(va_arg(vlst, long int)));
	return (ft_putchar_printf(va_arg(vlst, int), flags));
}

int		ft_sort_s(char *flags, va_list vlst)
{
	if (ft_detect(flags, 'l'))
		return (ft_putwstr_printf(va_arg(vlst, wchar_t*), flags));
	return (ft_putstr_printf(va_arg(vlst, char*), flags));
}

char	ft_find_conv(const char *format)
{
	while (*format && *format != 's' && *format != 'd' && *format != 'i'
	&& *format != 'u' && *format != '%' && *format != 'c' && *format != 'x'
	&& *format != 'o' && *format != 'X' && *format != 'S' && *format != 'S'
	&& *format != 'S' && *format != 'C' && *format != 'p' && *format != 'D'
	&& *format != 'O' && *format != 'U')
	{
		if (*format != '+' && *format != '-' && *format != ' ' && *format != '#'
		&& *format != 'l' && *format != 'h' && *format != 'z' && *format != 'j'
		&& *format != '0' && (*format < '0' || *format > '9') && *format != '.')
			return (*format);
		format++;
	}
	return (*format);
}

int		ft_getprec(char *flags)
{
	while (*flags)
	{
		if (*flags++ == '.')
			return (ft_atoi(flags));
	}
	return (0);
}
