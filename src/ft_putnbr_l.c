/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:35:09 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:35:11 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"
#include <inttypes.h>

static int ft_sign_cases(intmax_t *n, char *flags, char **to_dsp)
{
	if (*n < 0)
	{
		if (*n == LONG_MIN)
		{
			*to_dsp = ft_makestr("-9223372036854775808");
			return (20);
		}
		*n = -(*n);
		*to_dsp = ft_addchar(to_dsp, '-');
		return (1);
	}
	if (ft_detect(flags, '+'))
	{
		*to_dsp = ft_addchar(to_dsp, '+');
		return (1);
	}
	else if (ft_detect(flags, ' '))
	{
		*to_dsp = ft_addchar(to_dsp, ' ');
		return (1);
	}
	return (0);
}

static int	ft_process(intmax_t n, char **to_dsp)
{
	long int		mem;
	long int		div;
	long int		i;

	i = 0;
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		mem = (n / div);
		*to_dsp = ft_addchar(to_dsp, mem + '0');
		n = n - (mem * div);
		div = div / 10;
		i++;
	}
	return (i);
}

int			ft_putnbr_l(intmax_t n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	to_dsp = ft_strnew(0);
	padding = ft_makestr(" ");
	i = ft_sign_cases(&n, flags, &to_dsp);
	if (i != 20)
		i += ft_process(n, &to_dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right(&to_dsp, width, i));
		else
		{
			ft_handle_null(flags, &padding, &to_dsp, &to_del);
			i += ft_handle_wdth(width, &padding, &to_del, &to_dsp) + 1;
		}
	}
	ft_putstr(to_dsp);
	ft_strdel(&to_dsp);
	return (i);
}
