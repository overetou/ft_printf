/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:42:41 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:42:42 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(unsigned int n, int i, char **dsp)
{
	char	base[17];

	ft_strcpy(base, "0123456789ABCDEF");
	if (n / 16 != 0)
		i = ft_process(n / 16, i, dsp);
	*dsp = ft_addchar(dsp, base[n % 16]);
	return (i + 1);
}

static int	ft_handle_sharp(char **dsp, char *flags, unsigned int n)
{
	if (n == 0)
		return (0);
	if (ft_detect(flags, '#'))
	{
		*dsp = ft_strfuse(dsp, "0X");
		return (2);
	}
	return (0);
}

int			ft_pn_mhex(unsigned int n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	ft_initialise(&dsp, &pad);
	i = ft_handle_sharp(&dsp, flags, n);
	i += ft_add_prec_mx(ft_process(n, 0, &dsp), ft_getprec(flags), &dsp, flags);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_set_to_null(&i, &dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_pad_right(&dsp, width, i));
		else
		{
			ft_handle_null_mx(flags, &pad, &dsp, &del);
			i += ft_handle_wdth_x(width, &pad, &del, &dsp) + 1;
		}
	}
	ft_putstr(dsp);
	ft_strdel(&dsp);
	return (i);
}
