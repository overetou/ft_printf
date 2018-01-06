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

void	ft_putnbr_hex(unsigned int n)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		ft_putnbr_hex(n / 16);
	ft_putchar(base[n % 16]);
}
