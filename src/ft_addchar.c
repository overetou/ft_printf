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
	char c_str[1];

	c_str[0] = c;
	new = ft_strfuse(str, c_str);
	return (new);
}
