/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:40:26 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:40:31 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_makestr(char *content)
{
	char *new;

	if (!content)
		return (ft_makestr("(null)"));
	new = ft_strnew(ft_strlen(content) - 1);
	ft_strcpy(new, content);
	return (new);
}
