/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:44:27 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:44:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putunbr(unsigned int n)
{
	int				mem;
	unsigned int	div;
	int				i;

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
