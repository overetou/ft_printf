/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:28:46 by overetou          #+#    #+#             */
/*   Updated: 2018/01/08 15:28:48 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_to_str(char c, int *sz)
{
	char *new;

	new = ft_strnew(1);
	*new = c;
	*sz = 1;
	return (new);
}
