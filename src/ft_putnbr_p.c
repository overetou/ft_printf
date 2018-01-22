/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:33:18 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 16:33:20 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_back(int *i, char **dsp)
{
	ft_strdel(dsp);
	*dsp = ft_makestr("0x");
	*i = 2;
}

static void	ft_handle_null_p(char *flags, char **pad, char **dsp, char **del)
{
	if (ft_detect_0(flags))
	{
		**pad = '0';
		*del = ft_makestr("0x");
		(*dsp)[1] = '0';
		return ;
	}
	*del = ft_makestr(" ");
}

static int	ft_process(unsigned long int n, int i, char **dsp)
{
	char	base[16];

	ft_strcpy(base, "0123456789abcdef");
	if (n / 16 != 0)
		i = ft_process(n / 16, i, dsp);
	*dsp = ft_addchar(dsp, base[n % 16]);
	return (i + 1);
}

static int	ft_add_precision_p(int i, int prec, char **dsp)
{
	char *del;
	char *clean;

	del = ft_makestr("0x");
	while (prec > i)
	{
		i++;
		del = ft_strfuse(&del, "0");
	}
	clean = *dsp;
	*dsp = ft_strfuse(&del, *dsp);
	ft_strdel(&clean);
	return (i);
}

int			ft_pn_p(unsigned long int n, char *flags)
{
	int		i;
	char	*del;
	char	*dsp;
	int		width;
	char	*pad;

	ft_initialise(&dsp, &pad);
	i = ft_process(n, 0, &dsp);
	i = ft_add_precision_p(i, ft_getprec(flags), &dsp) + 2;
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_back(&i, &dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_pad_right(&dsp, width, i));
		else
		{
			ft_handle_null_p(flags, &pad, &dsp, &del);
			i += ft_handle_wdth_x(width, &pad, &del, &dsp) + 1;
		}
	}
	ft_putstr(dsp);
	ft_strdel(&dsp);
	ft_strdel(&pad);
	return (i);
}
