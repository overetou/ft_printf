/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:42:41 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:42:42 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(unsigned int n, int i)
{
	char	base[] = "0123456789ABCDEF";
	
	if (n / 16 != 0)
		i = ft_process(n / 16, i);
	ft_putchar(base[n % 16]);
	return (i + 1);
}

int	ft_putnbr_mhex(unsigned int n, char *flags)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (*flags++ == '#' && n)
		{
			i = ft_putstr("0X");
			break;
		}
	}
	return (ft_process(n, 0) + i);
}
