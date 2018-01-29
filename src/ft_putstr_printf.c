/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:20:26 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 16:20:55 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_truncate(char **dsp, int *i, int prec)
{
	char *to_del;

	if (!dsp)
		return ;
	to_del = *dsp;
	*dsp = ft_strnew(prec);
	ft_strncpy(*dsp, to_del, prec);
	ft_strdel(&to_del);
	*i = prec;
}

int			ft_putstr_printf(char *str, char *flags)
{
	int		i;
	char	*dsp;
	int		width;
	char	*pad;
	int		prec;

	if (!str && !ft_getwidth(flags) && !ft_detect(flags, '.'))
		dsp = ft_makestr("(null)");
	else
		dsp = ft_makestr(str);
	i = (int)ft_strlen(dsp);
	if ((prec = ft_getprec(flags)) < i && ft_detect(flags, '.'))
		ft_truncate(&dsp, &i, prec);
	if ((width = ft_getwidth(flags)) > i)
	{
		if (ft_detect(flags, '-'))
			return (ft_pad_right(&dsp, width - i, i));
		pad = ft_makestr(ft_detect_0ud(flags) ? "0" : " ");
		ft_handle_width_c(&pad, &dsp, &i, width - 1);
	}
	write(1, dsp, i);
	ft_strdel(&dsp);
	return (i);
}
