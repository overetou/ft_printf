/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:34:19 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:34:22 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int s;
	int i;

	va_start(vlst, format);
	i = 0;
	while (*format)
	{
		s = ft_print_until_flag(format);
		format += s;
		i += s;
		if (*format)
		{
			while (*(format + 1) == ' ')
				format++;
			s = ft_process_flag(&format, vlst);
			if (s != -1)
			{
				i += s;
				format++;
			}
		}
	}
	va_end(vlst);
	return (i);
}
