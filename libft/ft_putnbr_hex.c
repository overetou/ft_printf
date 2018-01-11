/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:42:15 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:42:18 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_process(unsigned int n, int i)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		i = ft_process(n / 16, i);
	ft_putchar(base[n % 16]);
	return (i + 1);
}

int	ft_putnbr_hex(unsigned int n, int to_print)
{
	int i;

	i = 0;
	if (n && !to_print)
		i = ft_putstr("0x");
	return (ft_process(n, 0) + i);
}
