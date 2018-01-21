/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_diuoxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:53:10 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 17:53:12 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort_di(char *flags, va_list vlst)
{
	if (ft_count(flags, 'z'))
		return (ft_pn_l((size_t)va_arg(vlst, intmax_t), flags));
	else if (ft_detect(flags, 'j'))
		return (ft_pn_l(va_arg(vlst, intmax_t), flags));
	else if (ft_count(flags, 'l') == 1)
		return (ft_pn_l((long int)va_arg(vlst, intmax_t), flags));
	else if (ft_count(flags, 'h') == 2)
		return (ft_pn_printf((signed char)va_arg(vlst, int), flags));
	else if (ft_count(flags, 'h') == 1)
		return (ft_pn_printf((short)va_arg(vlst, int), flags));
	else if (ft_count(flags, 'l') == 2)
		return (ft_pn_l((long long int)va_arg(vlst, intmax_t), flags));
	else
		return (ft_pn_printf(va_arg(vlst, int), flags));
}

int	ft_sort_u(char *f, va_list vlst)
{
	if (ft_count(f, 'h') == 1)
		return (ft_pun((unsigned short)va_arg(vlst, unsigned int), f));
	else if (ft_count(f, 'h') == 2)
		return (ft_pun((unsigned char)va_arg(vlst, unsigned int), f));
	else if (ft_count(f, 'z'))
		return (ft_pun_l((size_t)va_arg(vlst, uintmax_t), f));
	else if (ft_count(f, 'l') == 1)
		return (ft_pun_l((unsigned long int)va_arg(vlst, uintmax_t), f));
	else if (ft_count(f, 'l') == 2)
		return (ft_pun_l((unsigned long long int)va_arg(vlst, uintmax_t), f));
	else if (ft_detect(f, 'j'))
		return (ft_pun_l(va_arg(vlst, uintmax_t), f));
	else
		return (ft_pun(va_arg(vlst, unsigned int), f));
}

int	ft_sort_o(char *f, va_list vlst)
{
	if (ft_count(f, 'h') == 1)
		return (ft_pn_oct((unsigned short)va_arg(vlst, unsigned int), f));
	else if (ft_count(f, 'h') == 2)
		return (ft_pn_oct((unsigned char)va_arg(vlst, unsigned int), f));
	else if (ft_count(f, 'z'))
		return (ft_pn_loct((size_t)va_arg(vlst, uintmax_t), f));
	else if (ft_count(f, 'l') == 1)
		return (ft_pn_loct((unsigned long int)va_arg(vlst, uintmax_t), f));
	else if (ft_count(f, 'l') == 2)
		return (ft_pn_loct((unsigned long long int)va_arg(vlst, uintmax_t), f));
	else if (ft_detect(f, 'j'))
		return (ft_pn_loct(va_arg(vlst, uintmax_t), f));
	else
		return (ft_pn_oct(va_arg(vlst, unsigned int), f));
}

int	ft_sort_x(char *f, va_list vlst)
{
	if (ft_count(f, 'h') == 1)
		return (ft_pn_hex((unsigned short)va_arg(vlst, unsigned int), f));
	else if (ft_count(f, 'h') == 2)
		return (ft_pn_hex((unsigned char)va_arg(vlst, unsigned int), f));
	else if (ft_count(f, 'z'))
		return (ft_pn_lhex((size_t)va_arg(vlst, uintmax_t), f));
	else if (ft_count(f, 'l') == 1)
		return (ft_pn_lhex((unsigned long int)va_arg(vlst, uintmax_t), f));
	else if (ft_count(f, 'l') == 2)
		return (ft_pn_lhex((unsigned long long int)va_arg(vlst, uintmax_t), f));
	else if (ft_detect(f, 'j'))
		return (ft_pn_lhex(va_arg(vlst, uintmax_t), f));
	else
		return (ft_pn_hex(va_arg(vlst, unsigned int), f));
}

int	ft_sort_xx(char *f, va_list v)
{
	if (ft_count(f, 'h') == 1)
		return (ft_pn_mhex((unsigned short)va_arg(v, unsigned int), f));
	else if (ft_count(f, 'h') == 2)
		return (ft_pn_mhex((unsigned char)va_arg(v, unsigned int), f));
	else if (ft_count(f, 'z'))
		return (ft_pn_mlhex((size_t)va_arg(v, uintmax_t), f));
	else if (ft_count(f, 'l') == 1)
		return (ft_pn_mlhex((unsigned long int)va_arg(v, uintmax_t), f));
	else if (ft_count(f, 'l') == 2)
		return (ft_pn_mlhex((unsigned long long int)va_arg(v, uintmax_t), f));
	else if (ft_detect(f, 'j'))
		return (ft_pn_mlhex(va_arg(v, uintmax_t), f));
	else
		return (ft_pn_mhex(va_arg(v, unsigned int), f));
}
