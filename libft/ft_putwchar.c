/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:45:25 by overetou          #+#    #+#             */
/*   Updated: 2018/01/06 18:45:28 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char	*ft_create_binary(unsigned int n, unsigned int x)
{
	char *bin;
	char c[1];
	char *to_del;

	if (n / 2 == 0)
		to_del = ft_strnew(0);
	else
		to_del = ft_create_binary(n / 2, x++);
	c[0] = n % 2 + '0';
	bin = ft_strjoin(to_del, c);
	ft_strdel(&to_del);
	return (bin);
}

static char	*ft_fill_mask(char *oct, char *bin)
{
	unsigned int	o;
	int				b;

	o = ft_strlen(oct) - 1;
	b = ft_strlen(bin) - 1;
	while (o && b != -1)
	{
		if (oct[o] == 'x')
			oct[o] = bin[b--];
		o--;
	}
	while (o)
	{
		if (oct[o] == 'x')
			oct[o] = '0';
		o--;
	}
	return (oct);
}

static int	ft_get_next_dec(char **oct)
{
	int		i;
	int		p;
	int 	d;

	i = 0;
	while ((*oct)[i] == 'x')
		i++;
	if (i)
		i++;
	d = 0;
	p = 8;
	while (p-- != 0)
	{
		if ((*oct)[i] != '0')
			d = d + (((*oct)[i] - '0') * ft_power(2, p));
		(*oct)[i++] = 'x';
	}
	if (!((*oct)[i]))
		(*oct)[0] = '\0';
	return (d);
}

char	*ft_generate_mask(size_t b_size)
{
	size_t	av_space;
	size_t	frst_oct;
	size_t	n_of_masks;
	char	*mask = " 10xxxxxx";
	char 	*oct;

	oct = ft_makestr("1xxxxxxx");
	av_space = 7;
	frst_oct = 7;
	n_of_masks = 1;
	while (av_space < b_size)
		av_space = --frst_oct + 6 * n_of_masks++;
	av_space = 1;
	while (av_space != n_of_masks)
		oct[av_space++] = '1';
	oct[av_space] = '0';
	while (n_of_masks-- != 1)
		oct = ft_strfuse(&oct, mask);
	return (oct);
}

void	ft_putwchar(wchar_t wc)
{
    char	*bin;
    size_t	b_size;
    char	*oct;
    int 	c;

    bin = ft_create_binary(wc, 0);
    b_size = ft_strlen(bin);
    if (b_size < 8)
    {
    	ft_putchar(wc);
    	return ;
    }
    else
    	oct = ft_generate_mask(b_size);
    oct = ft_fill_mask(oct, bin);
    ft_strdel(&bin);
    while (*oct)
    {
    	c = ft_get_next_dec(&oct);
    	write(1, &c, 1);
    }
    ft_strdel(&oct);
}
