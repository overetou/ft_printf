/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:15:05 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 18:15:07 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_conv_two(char conv, va_list vlst, char *flags)
{
	int i;

	if (conv == 'X')
		i = ft_sort_xx(flags, vlst);
	else if (conv == 'S')
		i = ft_putwstr_printf(va_arg(vlst, wchar_t*), flags);
	else if (conv == 'C')
		i = ft_handle_wchar((wchar_t)va_arg(vlst, wchar_t*), flags);
	else if (conv == 'p')
		i = ft_pn_p(va_arg(vlst, unsigned long int), flags);
	else if (conv == 'D')
		i = ft_pn_l(va_arg(vlst, long int), flags);
	else if (conv == 'O')
		i = ft_pn_loct(va_arg(vlst, unsigned long int), flags);
	else if (conv == 'U')
		i = ft_pun_l(va_arg(vlst, unsigned long int), flags);
	else
		return (-1);
	return (i);
}

int			ft_process_conv(char conv, va_list vlst, char *flags)
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
		i = ft_putchar_printf('%', flags);
	else if (conv == 'c')
		i = ft_sort_c(flags, vlst);
	else if (conv == 'x')
		i = ft_sort_x(flags, vlst);
	else if (conv == 'o')
		i = ft_sort_o(flags, vlst);
	else
		return (ft_process_conv_two(conv, vlst, flags));
	return (i);
}
