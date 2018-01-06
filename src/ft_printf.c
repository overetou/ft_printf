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

int		ft_printf(char const *format, ...)
{
	va_list	vlst;
	int		sz_to_add;
	char	*current_str;

	(void)vlst;
	current_str = ft_strnew(0);
	while (*format)
	{
		current_str = ft_strfuse(&current_str, ft_get_till_flag(format, &sz_to_add));
		format += sz_to_add;
		if (*format == '%')
			format++;
	}
	ft_putstr(current_str);
	return (ft_strlen(current_str));
}
