/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pn_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:42:15 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:42:18 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle_wdth_x(int width, char **pad, char **del, char **dsp)
{
	int i;

	i = 0;
	while (--width)
	{
		i++;
		*pad = ft_addchar(pad, **pad);
	}
	if (**del != ' ')
		ft_strncpy(*pad, *del, 2);
	ft_strdel(del);
	*del = *dsp;
	*dsp = ft_strfuse(pad, *dsp);
	ft_strdel(del);
	ft_strdel(pad);
	return (i);
}

int			ft_addprec_x(int i, int prec, char **dsp, char *flags)
{
	char *to_add;
	char *del;

	if (prec <= i)
		return (i);
	to_add = ft_strnew(0);
	if (ft_detect(flags, '#'))
	{
		to_add = ft_strfuse(&to_add, "0x");
		(*dsp)[1] = '0';
		i += 2;
	}
	while (prec > i)
	{
		i++;
		to_add = ft_addchar(&to_add, '0');
	}
	del = *dsp;
	*dsp = ft_strfuse(&to_add, *dsp);
	ft_strdel(&del);
	return (i);
}

static int	ft_process(unsigned int n, int i, char **dsp)
{
	char	base[17];

	ft_strcpy(base, "0123456789abcdef");
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
		*dsp = ft_strfuse(dsp, "0x");
		return (2);
	}
	return (0);
}

int			ft_pn_hex(unsigned int n, char *flags)
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
