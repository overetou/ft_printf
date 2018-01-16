/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:44:27 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:44:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(unsigned int n, char **to_dsp)
{
	int	mem;
	int	div;
	int	i;

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
int	ft_putunbr(unsigned int n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	ft_initialise(&to_dsp, &padding);
	i = ft_add_precision(ft_process(n, &to_dsp), ft_getprec(flags), &to_dsp);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_set_to_null(&i, &to_dsp);
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
