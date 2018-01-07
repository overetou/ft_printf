/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:10:11 by overetou          #+#    #+#             */
/*   Updated: 2018/01/07 20:10:14 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_nbr_to_str(int n)
{
	int		mem;
	size_t	div;
	char	*rvalue;

	rvalue = ft_strnew(0);
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_makestr("-2147483648"));
		rvalue = ft_addchar(&rvalue, '-');
		n = -n;
	}
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		mem = (n / div);
		rvalue = ft_addchar(&rvalue, (mem + '0'));
		n = n - (mem * div);
		div = div / 10;
	}
	return (rvalue);
}
