/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:45:25 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:45:28 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_count_oct(wchar_t wc)
{
	if (wc < 128)
		return (1);
	else if (wc < 2048)
		return (2);
	else if (wc < 65536)
		return (3);
	else
		return (0);
}

static int	ft_pad_right_ss(wchar_t wc, int width)
{
	int printed;

	printed = ft_putwchar(wc);
	while (width--)
		printed += ft_putchar(' ');
	return (printed);
}

int			ft_putwchar(wchar_t wc)
{
	int		n;
	char	wstring[4];
	wchar_t	cut;

	n = 1;
	if (wc < 128)
		wstring[0] = wc;
	else if (wc < 2048)
	{
		n = 2;
		wstring[0] = 192 | (wc >> 6);
		wstring[1] = 128 | (wc ^ ((wc >> 6) << 6));
	}
	else if (wc < 65536)
	{
		n = 3;
		cut = wc >> 6;
		wstring[0] = 224 | (cut >> 6);
		wstring[1] = 128 | (cut ^ ((cut >> 6) << 6));
		wstring[2] = 128 | (wc ^ (cut << 6));
	}
	write(1, &wstring, n);
	return (n);
}

int			ft_handle_wchar(wchar_t wc, char *flags)
{
	int		i;
	int		width;
	char	*pad;

	width = ft_getwidth(flags);
	i = ft_count_oct(wc);
	if ((width -= i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_pad_right_ss(wc, width));
		pad = ft_makestr((ft_detect_0ud(flags) ? "0" : " "));
		while (width--)
			i += ft_putchar(*pad);
		ft_strdel(&pad);
	}
	ft_putwchar(wc);
	return (i);
}
