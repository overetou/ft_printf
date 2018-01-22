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
	char c_str[2];

	c_str[0] = c;
	c_str[1] = '\0';
	return (ft_strfuse(str, c_str));
}

char	*ft_add_bfr(char *to_add, char **del)
{
	to_add = ft_strjoin(to_add, *del);
	ft_strdel(del);
	return (to_add);
}

int		ft_pad_right(char **dsp, int width, int i)
{
	ft_putstr(*dsp);
	ft_strdel(dsp);
	while (width--)
		i += ft_putchar(' ');
	return (i);
}

void	ft_set_to_null(int *i, char **dsp)
{
	*i = 0;
	ft_strdel(dsp);
	*dsp = ft_strnew(0);
}

void	ft_initialise(char **dsp, char **pad)
{
	*dsp = ft_strnew(0);
	*pad = ft_makestr(" ");
}
