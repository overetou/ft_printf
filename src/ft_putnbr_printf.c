/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:01:56 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 19:01:58 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sign_cases(int *n, char *flags, char **dsp)
{
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

static int	ft_process(int n, char **dsp)
{
	int				mem;
	unsigned int	div;
	int				i;

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

int			ft_pn_printf(int n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	ft_initialise(&dsp, &pad);
	i = ft_sign_cases(&n, flags, &dsp);
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
