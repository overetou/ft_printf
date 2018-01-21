/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:36:05 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:36:07 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(uintmax_t n, char **dsp)
{
	unsigned long int	mem;
	unsigned long int	div;
	unsigned long int	i;

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

int			ft_pun_l(uintmax_t n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	ft_initialise(&dsp, &pad);
	i = ft_add_precision(ft_process(n, &dsp), ft_getprec(flags), &dsp);
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
