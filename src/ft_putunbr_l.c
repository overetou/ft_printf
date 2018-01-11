/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:36:05 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:36:07 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putunbr_l(unsigned long int n)
{
	unsigned long int	mem;
	unsigned long int	div;
	unsigned long int	i;

	i = 0;
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		mem = (n / div);
		ft_putchar(mem + '0');
		n = n - (mem * div);
		div = div / 10;
		i++;
	}
	return (i);
}
