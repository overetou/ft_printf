/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:26:02 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 17:26:04 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_handle_width_c(char **pad, char **dsp, int *i, int width)
{
	char *to_del;

	while (width > (*i)++)
		*pad = ft_addchar(pad, **pad);
	to_del = *dsp;
	*dsp = ft_strfuse(pad, *dsp);
	ft_strdel(&to_del);
}

int		ft_putchar_printf(char c, char *flags)
{
	int		i;
	char	*dsp;
	int		width;
	char	*pad;

	ft_initialise(&dsp, &pad);
	dsp = ft_strnew(0);
	dsp = ft_addchar(&dsp, c);
	i = 1;
	if ((width = ft_getwidth(flags)) > i)
	{
		width--;
		if (ft_detect(flags, '-'))
			return (ft_pad_right(&dsp, width, i));
		else
		{
			if (ft_detect(flags, '0'))
				*pad = '0';
			ft_handle_width_c(&pad, &dsp, &i, width);
		}
	}
	write(1, dsp, i);
	ft_strdel(&dsp);
	return (i);
}
