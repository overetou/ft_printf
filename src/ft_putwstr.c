/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:36:43 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:36:45 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char	*ft_add_bfr(char *to_add, char **to_del)
{
	to_add = ft_strjoin(to_add, *to_del);
	ft_strdel(to_del);
	return (to_add);
}

static int	ft_putwstr(wchar_t *wstr, int n, int p, int prec)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (p && prec == n)
	{
		while (prec > i)
			i += ft_putwchar(wstr[x++]);
	}
	else
	{
		while (n--)
			i += ft_putwchar(wstr[x++]);
	}
	return (i);
}

static int	ft_handle_prec_S(int prec, char **dspright, int i)
{
	prec = prec - i;
	while (--prec)
			*dspright = ft_add_bfr("0", dspright);
		return (i);
}

static int ft_padding_right_S(char *wstr, int width, int i)
{
	int printed;

	printed = ft_putwstr((wchar_t*)wstr, i, 0, 0);
	while (width--)
		printed += ft_putchar(' ');
	return (printed);
}

static int	wft_strlen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

int			ft_putwstr_printf(char *wstr, char *flags)
{
	int		i;
	int		width;
	char	*dspright;
	char	*padding;

	width = ft_getwidth(flags);
	dspright = ft_strnew(0);
	if (!wstr && !width && !ft_detect(flags, '.'))
		return (ft_putstr("(null)"));
	i = wft_strlen((wchar_t*)wstr);
	if (ft_detect(flags, '.'))
		i = (ft_getprec(flags) > i ? ft_handle_prec_S(ft_getprec(flags), &dspright, i) : ft_getprec(flags));
	if ((width -= i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right_S(wstr, width, i));
		padding = ft_makestr((ft_detect_0(flags) ? "0" : " "));
		while (--width)
			dspright = ft_add_bfr(padding, &dspright);
	}
	i = ft_putstr(dspright) + ft_putwstr((wchar_t*)wstr, i, ft_detect(flags, '.'), ft_getprec(flags));
	ft_strdel(&dspright);
	return (i);
}
