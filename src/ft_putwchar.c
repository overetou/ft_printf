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

int	ft_putwchar(wchar_t wc)
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
