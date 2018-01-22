/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:43:01 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:43:02 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(unsigned int n, int i, char **dsp)
{
	char	base[9];

	ft_strcpy(base, "01234567");
	if (n / 8 != 0)
		i = ft_process(n / 8, i, dsp);
	*dsp = ft_addchar(dsp, base[n % 8]);
	return (i + 1);
}

static int	ft_handle_sharp(char **dsp, char *flags)
{
	if (**dsp == '0')
		return (0);
	if (ft_detect(flags, '#'))
	{
		*dsp = ft_add_bfr("0", dsp);
		return (1);
	}
	return (0);
}

int			ft_pn_oct(unsigned int n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	dsp = ft_strnew(0);
	i = ft_add_precision(ft_process(n, 0, &dsp), ft_getprec(flags), &dsp);
	i += ft_handle_sharp(&dsp, flags);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0
	&& !ft_detect(flags, '#'))
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
