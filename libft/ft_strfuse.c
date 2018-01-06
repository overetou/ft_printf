/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:46:25 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:46:26 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfuse(char **str1, char *str2)
{
	str2 = ft_strjoin(*str1, str2);
	ft_strdel(str1);
	return (str2);
}
