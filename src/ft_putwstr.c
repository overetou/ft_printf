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

int	ft_putwstr(wchar_t *wstr)
{
	int s;

	if (!wstr)
	{
		ft_putstr("(null)");
		return (6);
	}
	s = 0;
	while (*wstr)
		s += ft_putwchar(*wstr++);
	return (s);
}
