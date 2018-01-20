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

static int	wft_strlen(wchar_t *wstr)
{
	int sz;

	sz = 0;
	while (*wstr != '\0')
	{
		if (*wstr < 128)
			sz += 1;
		else if (*wstr < 2048)
			sz += 2;
		else if (*wstr < 65536)
			sz += 3;
		wstr++;
	}
	return (sz);
}

static int	ft_count_oct(wchar_t *wstr, int prec, char **dspleft)
{
	int sz;
	int add;
	int i;

	i = 0;
	sz = 0;
	add = 0;
	(void)dspleft;
	while (prec >= add + sz && wstr[i] != 0)
	{
		sz += add;
		if (wstr[i] < 128)
			add = 1;
		else if (wstr[i] < 2048)
			add = 2;
		else if (wstr[i] < 65536)
			add = 3;
		i++;
	}
	if (prec < add + sz)
		return (sz);
	else
		return (wft_strlen(wstr));
	return (sz);
}

static int	ft_putwstr(wchar_t *wstr, int n, int p, int prec)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (p && prec >= n)
	{
		while (n > i)
			i += ft_putwchar(wstr[x++]);
	}
	else
	{
		while (i < n)
			i += ft_putwchar(wstr[x++]);
	}
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

int			ft_putwstr_printf(char *wstr, char *flags)
{
	int		i;
	int		width;
	char	*dspleft;
	char	*padding;
	int		prec;

	width = ft_getwidth(flags);
	dspleft = ft_strnew(0);
	if (!wstr && !width && !ft_detect(flags, '.'))
		return (ft_putstr("(null)"));
	if (ft_detect(flags, '.'))
	{
		prec = ft_getprec(flags);
		i = ft_count_oct((wchar_t*)wstr, prec, &dspleft);
	}
	else
		i = wft_strlen((wchar_t*)wstr);
	if ((width -= i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right_S(wstr, width, i));
		padding = ft_makestr((ft_detect_0ud(flags) ? "0" : " "));
		while (width--)
			dspleft = ft_add_bfr(padding, &dspleft);
	}
	i = ft_putstr(dspleft) + ft_putwstr((wchar_t*)wstr, i, ft_detect(flags, '.'), prec);
	ft_strdel(&dspleft);
	return (i);
}
