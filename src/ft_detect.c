/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:32:16 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 17:32:19 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	ft_detect(char *flags, char to_find)
{
	while (*flags)
	{
		if (*flags++ == to_find)
			return (1);
	}
	return (0);
}

short	ft_detect_0ud(char *flags)
{
	while (*flags)
	{
		if (*flags == '0' && (*(flags - 1) < '1' || *(flags - 1) > '9'))
			return (1);
		flags++;
	}
	return (0);
}

int		ft_count(char *flags, char to_find)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (*flags++ == to_find)
			i++;
	}
	return (i);
}

short	ft_detect_0(char *flags)
{
	if (ft_detect(flags, '.'))
		return (0);
	while (*flags)
	{
		if (*flags == '0' && (*(flags - 1) < '1' || *(flags - 1) > '9'))
			return (1);
		flags++;
	}
	return (0);
}
