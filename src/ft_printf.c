/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:32:28 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 19:27:02 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*ft_get_till_flag(const char *str, int *i)
{
	char	*rvlue; 

	*i = 0;
	while (str[*i] != '%' && str[*i])
		(*i)++;
	rvlue = ft_strnew(*i);
	return (ft_strncpy(rvlue, str, *i));
}

char	*ft_prcess(const char *format, va_list vlst)
{
	char	*to_display;

	if (*format == 's')
		to_display = ft_makestr(va_arg(vlst, char*));
	else if (*format == 'd' || *format == 'i')
		to_display = ft_nbr_to_str(va_arg(vlst, int));
	else if (*format == '%')
		to_display = ft_makestr("%");
	else
		return (NULL);
	return (to_display);
}

int		ft_printf(char const *format, ...)
{
	va_list	vlst;
	int		sz_to_add;
	char	*current_str;
	char	*to_delete;

	va_start(vlst, format);
	current_str = ft_strnew(0);
	while (*format)
	{
		to_delete = ft_get_till_flag(format, &sz_to_add);
		current_str = ft_strfuse(&current_str, to_delete);
		ft_strdel(&to_delete);
		format += sz_to_add;
		if (*format == '%')
		{
			format++;
			to_delete = ft_prcess(format++, vlst);
			current_str = ft_strfuse(&current_str, to_delete);
			ft_strdel(&to_delete);
		}
	}
	ft_putstr(current_str);
	va_end(vlst);
	return (ft_strlen(current_str));
}
