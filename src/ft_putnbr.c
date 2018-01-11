/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:01:56 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 19:01:58 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process(int n)
{
	int				mem;
	unsigned int	div;
	int				i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
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

int	ft_putnbr(int n, char *flags)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (*flags++ == '+')
		{
			if (n >= 0)
				i = ft_putchar('+');
		}
	}
	return (ft_process(n) + i);
}