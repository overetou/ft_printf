/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:01:56 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 19:01:58 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_sign_cases(int *n, char *flags, char **to_dsp)
{
	if (*n < 0)
	{
		*n = -(*n);
		*to_dsp = ft_addchar(to_dsp, '-');
		return (1);
	}
	if (ft_detect(flags, '+'))
		return (ft_putchar('+'));
	else if (ft_detect(flags, ' '))
	{
		*to_dsp = ft_addchar(to_dsp, ' ');
		return (1);
	}
	return (0);
}

static int	ft_process(int n, char **to_dsp)
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
		*to_dsp = ft_addchar(to_dsp, mem + '0');
		n = n - (mem * div);
		div = div / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	to_dsp = ft_strnew(0);
	padding = ft_makestr(" ");
	i = ft_sign_cases(&n, flags, &to_dsp);
	i += ft_process(n, &to_dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '0'))
			padding[0] = '0';
		while (width--)
		{
			to_del = to_dsp;
			to_dsp = ft_strjoin(padding, to_dsp);
			ft_strdel(&to_del);
			i++;
		}
	}
	ft_putstr(to_dsp);
	return (i);
}