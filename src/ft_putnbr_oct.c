/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:43:01 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:43:02 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(unsigned int n, int i)
{
	char	base[] = "01234567";
	
	if (n / 8 != 0)
		i = ft_process(n / 8, i);
	ft_putchar(base[n % 8]);
	return (i + 1);
}

int ft_putnbr_oct(unsigned int n, char *flags)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (*flags++ == '#' && n)
		{
			i = ft_putstr("0");
			break;
		}
	}
	return (ft_process(n, 0) + i);
}
