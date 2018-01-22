/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:33:02 by overetou          #+#    #+#             */
/*   Updated: 2018/01/21 17:33:04 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getwidth(char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '.')
			return (0);
		if (flags[i] > '0' && flags[i] <= '9')
			return (ft_atoi(flags + i));
		i++;
	}
	return (0);
}

int		ft_add_precision(int i, int prec, char **dsp)
{
	char *to_add;
	char *del;

	if (prec <= i)
		return (i);
	to_add = ft_strnew(0);
	if (**dsp == '+' || **dsp == '-' || **dsp == ' ')
	{
		to_add = ft_addchar(&to_add, **dsp);
		**dsp = '0';
		i++;
	}
	while (prec > i)
	{
		i++;
		to_add = ft_addchar(&to_add, '0');
	}
	del = *dsp;
	*dsp = ft_strfuse(&to_add, *dsp);
	ft_strdel(&del);
	return (i);
}

void	ft_handle_null(char *flags, char **pad, char **dsp, char **del)
{
	*del = ft_makestr("x");
	if (ft_detect_0(flags))
	{
		*pad = ft_makestr("0");
		if (**dsp == '+' || **dsp == '-' || **dsp == ' ')
		{
			**del = **dsp;
			**dsp = '0';
		}
		return ;
	}
	*pad = ft_makestr(" ");
}

int		ft_handle_wdth(int width, char **pad, char **del, char **dsp)
{
	int i;

	i = 0;
	while (--width)
	{
		i++;
		*pad = ft_addchar(pad, **pad);
	}
	if (**del != 'x')
		**pad = **del;
	ft_strdel(del);
	*del = *dsp;
	*dsp = ft_strfuse(pad, *dsp);
	ft_strdel(del);
	ft_strdel(pad);
	return (i);
}

void	ft_handle_null_x(char *flags, char **pad, char **dsp, char **del)
{
	if (ft_detect_0(flags))
	{
		**pad = '0';
		if (ft_detect(flags, '#'))
		{
			*del = ft_makestr("0x");
			(*dsp)[1] = '0';
			return ;
		}
	}
	*del = ft_makestr(" ");
}
