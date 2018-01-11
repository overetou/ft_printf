/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:35:30 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:35:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_pointer(long int n, int i)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		i = ft_put_pointer(n / 16, i);
	ft_putchar(base[n % 16]);
	return (i + 1);
}

int			ft_putnbr_lhex(long int n)
{
	ft_putstr("0x");
	return (ft_put_pointer(n, 2));
}
