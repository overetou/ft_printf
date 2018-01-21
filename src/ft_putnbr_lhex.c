/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:35:30 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:35:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(uintmax_t n, int i, char **dsp)
{
	char	base[16];

	ft_strcpy(base, "0123456789abcdef");
	if (n / 16 != 0)
		i = ft_process(n / 16, i, dsp);
	*dsp = ft_addchar(dsp, base[n % 16]);
	return (i + 1);
}

static int	ft_handle_sharp(char **dsp, char *flags, uintmax_t n)
{
	if (n == 0)
		return (0);
	if (ft_detect(flags, '#'))
	{
		*dsp = ft_strfuse(dsp, "0x");
		return (2);
	}
	return (0);
}

int			ft_pn_lhex(uintmax_t n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	ft_initialise(&dsp, &pad);
	i = ft_handle_sharp(&dsp, flags, n);
	i += ft_addprec_x(ft_process(n, 0, &dsp), ft_getprec(flags), &dsp, flags);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_set_to_null(&i, &dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_pad_right(&dsp, width, i));
		else
		{
			ft_handle_null_x(flags, &pad, &dsp, &del);
			i += ft_handle_wdth_x(width, &pad, &del, &dsp) + 1;
		}
	}
	ft_putstr(dsp);
	ft_strdel(&dsp);
	return (i);
}
