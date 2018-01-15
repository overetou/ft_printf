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

int		ft_add_precision(int i, int prec, char **to_dsp)
{
	char *to_add;
	char *to_del;

	if (prec == 0)
	{
		ft_strdel(to_dsp);
		*to_dsp = ft_makestr("");
		return (0);
	}
	if (prec <= i)
		return (i);
	to_add = ft_strnew(0);
	if (**to_dsp == '+' || **to_dsp == '-')
	{
		to_add = ft_addchar(&to_add, **to_dsp);
		**to_dsp = '0';
		i++;
	}
	while (prec > i)
	{
		i++;
		to_add = ft_addchar(&to_add, '0');
	}
	to_del = *to_dsp;
	*to_dsp = ft_strfuse(&to_add, *to_dsp);
	ft_strdel(&to_del);
	return (i);
}

void	ft_handle_null(char *flags, char **padding, char **to_dsp, char **to_del)
{
	*to_del = ft_makestr(" ");
	if (ft_detect(flags, '0') && !ft_detect(flags, '-'))
	{
		**padding = '0';
		if (**to_dsp == '+' || **to_dsp == '-')
		{
			**to_del = **to_dsp;
			**to_dsp = **padding;
		}
	}
}

int		ft_handle_wdth(int width, char **padding, char **to_del, char **to_dsp)
{
	int i;

	i = 0;
	while (--width)
	{
		i++;
		*padding = ft_addchar(padding, **padding);
	}
	if (**to_del != ' ')
			**padding = **to_del;
		ft_strdel(to_del);
		*to_del = *to_dsp;
		*to_dsp = ft_strfuse(padding, *to_dsp);
	ft_strdel(to_del);
	ft_strdel(padding);
	return (i);
}

int ft_padding_right(char **to_dsp, int width, int i)
{
	ft_putstr(*to_dsp);
	ft_strdel(to_dsp);
	while (width--)
		i += ft_putchar(' ');
	return (i);
}

static int ft_sign_cases(int *n, char *flags, char **to_dsp)
{
	if (*n < 0)
	{
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

int	ft_putnbr_printf(int n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	to_dsp = ft_strnew(0);
	padding = ft_makestr(" ");
	i = ft_sign_cases(&n, flags, &to_dsp);
	i += ft_add_precision(ft_process(n, &to_dsp), ft_getprec(flags), &to_dsp);
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