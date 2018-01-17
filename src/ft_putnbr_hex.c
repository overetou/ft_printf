/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:42:15 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:42:18 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(unsigned int n, int i, char **to_dsp)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		i = ft_process(n / 16, i, to_dsp);
	*to_dsp = ft_addchar(to_dsp, base[n % 16]);
	return (i + 1);
}

static int ft_handle_sharp(char **to_dsp, char *flags, int n)
{
	if (n == 0)
		return (0);
	if (ft_detect(flags, '#'))
	{
		*to_dsp = ft_strfuse(to_dsp, "0x");
		return (2);
	}
	return (0);
}

int	ft_putnbr_hex(unsigned int n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	ft_initialise(&to_dsp, &padding);
	i = ft_handle_sharp(&to_dsp, flags, n);
	i += ft_add_precision_x(ft_process(n, 0, &to_dsp), ft_getprec(flags), &to_dsp, flags);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_set_to_null(&i, &to_dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right(&to_dsp, width, i));
		else
		{
			ft_handle_null_x(flags, &padding, &to_dsp, &to_del);
			i += ft_handle_wdth_x(width, &padding, &to_del, &to_dsp) + 1;
		}
	}
	ft_putstr(to_dsp);
	ft_strdel(&to_dsp);
	return (i);
}
