/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:32:29 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 16:32:32 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent(char *flags)
{
	int width;
	int i;

	width = ft_getwidth(flags) - 1;
	i = 1;
	if (ft_detect(flags, '-'))
	{
		ft_putchar('%');
		while (width-- > 0)
			i += ft_putchar(' ');
		return (i);
	}
	while (width-- > 0)
		i += ft_putchar(' ');
	ft_putchar('%');
	return (i);
}
