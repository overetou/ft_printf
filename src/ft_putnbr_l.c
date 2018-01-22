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

static int	ft_sign_cases(intmax_t *n, char *flags, char **dsp)
{
	if (*n == LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return (20);
	}
	if (*n < 0)
	{
		*n = -(*n);
		*dsp = ft_addchar(dsp, '-');
		return (1);
	}
	if (ft_detect(flags, '+'))
	{
		*dsp = ft_addchar(dsp, '+');
		return (1);
	}
	else if (ft_detect(flags, ' '))
	{
		*dsp = ft_addchar(dsp, ' ');
		return (1);
	}
	return (0);
}

static int	ft_process(intmax_t n, char **dsp)
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
		*dsp = ft_addchar(dsp, mem + '0');
		n = n - (mem * div);
		div = div / 10;
		i++;
	}
	return (i);
}

int			ft_pn_l(intmax_t n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	dsp = ft_strnew(0);
	if ((i = ft_sign_cases(&n, flags, &dsp)) == 20)
		return (20);
	i += ft_add_precision(ft_process(n, &dsp), ft_getprec(flags), &dsp);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_set_to_null(&i, &dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_pad_right(&dsp, width, i));
		else
		{
			ft_handle_null(flags, &pad, &dsp, &del);
			i += ft_handle_wdth(width, &pad, &del, &dsp) + 1;
		}
	}
	ft_putstr(dsp);
	ft_strdel(&dsp);
	return (i);
}
