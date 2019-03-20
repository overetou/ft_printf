/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:37:32 by overetou          #+#    #+#             */
/*   Updated: 2018/01/11 19:37:34 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strnput(char *str, int n)
{
	int i;

	i = 0;
	while (i != n)
		ft_putchar(str[i++]);
}