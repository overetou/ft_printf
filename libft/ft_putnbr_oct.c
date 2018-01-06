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

#include "libft.h"

void	ft_putnbr_oct(unsigned int n)
{
	char	base[] = "01234567";
	
	if (n / 8 != 0)
		ft_putnbr_oct(n / 8);
	ft_putchar(base[n % 8]);
}
