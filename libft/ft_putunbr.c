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

#include "libft.h"

void		ft_putunbr(unsigned int n)
{
	unsigned int	mult;
	unsigned int	res;

	mult = 1;
	while (n / mult > 10)
		mult *= 10;
	while (mult != 0)
	{
		res = n / mult;
		ft_putchar(res + '0');
		n = n - (res * mult);
		mult = mult / 10;
	}
}
