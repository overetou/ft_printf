/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:16:49 by overetou          #+#    #+#             */
/*   Updated: 2018/01/07 20:16:54 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_addchar(char **str, char c)
{
	char *new;
	int i = 0;

	new = ft_strfuse(str, "0");
	while (new[i])
		i++;
	new[i - 1] = c;
	return (new);
}
