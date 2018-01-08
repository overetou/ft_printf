/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:06:12 by overetou          #+#    #+#             */
/*   Updated: 2018/01/08 15:06:15 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_unbr_to_str(size_t n, int *sz)
{
	size_t	mem;
	size_t	div;
	char	*rvalue;

	rvalue = ft_strnew(0);
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
	*sz = ft_strlen(rvalue);
	return (rvalue);
}
