/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:34:34 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:34:36 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>
#include <unistd.h>

static int	ft_do_udf_bhv(char c, char *flags)
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
			if (ft_detect_0ud(flags))
				*pad = '0';
			ft_handle_width_c(&pad, &dsp, &i, width);
		}
	}
	write(1, dsp, i);
	ft_strdel(&dsp);
	return (i);
}

static char	*ft_find_flags(const char **format, char conv)
{
	char *new;

	new = ft_strnew(0);
	while (**format != conv)
	{
		new = ft_addchar(&new, **format);
		(*format)++;
	}
	return (new);
}

int			ft_process_flag(const char **format, va_list vlst)
{
	char	conv;
	char	*flags;
	int		ret;

	(*format)++;
	conv = ft_find_conv(*format);
	flags = ft_find_flags(format, conv);
	ret = ft_process_conv(conv, vlst, flags);
	if (ret == -1)
	{
		if (conv == '\0')
		{
			ret = 0;
			(*format)--;
		}
		else
			ret = ft_do_udf_bhv(conv, flags);
	}
	ft_strdel(&flags);
	return (ret);
}
