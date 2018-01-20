#include "ft_printf.h"
#include <unistd.h>

static void	ft_truncate(char **to_dsp, int *i, int prec)
{
	char *to_del;

	to_del = *to_dsp;
	*to_dsp = ft_strnew(prec);
	ft_strncpy(*to_dsp, to_del, prec);
	ft_strdel(&to_del);
	*i = prec;
}

int			ft_putstr_printf(char *str, char *flags)
{
	int		i;
	char	*to_dsp;
	int		width;
	char	*padding;
	int 	prec;

	if (!str && !ft_getwidth(flags) && !ft_detect(flags, '.'))
	{
		write(1, "(null)", 6);
		return (6);
	}
	padding = ft_makestr(" ");
	i = (int)ft_strlen(str);
	to_dsp = ft_strnew(i);
	ft_strcpy(to_dsp, str);
	if ((prec = ft_getprec(flags)) < i && ft_detect(flags, '.'))
		ft_truncate(&to_dsp, &i, prec);
	if ((width = ft_getwidth(flags)) > i)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right(&to_dsp, width - i, i));
		width--;
		if (ft_detect(flags, '0'))
			*padding = '0';
		ft_handle_width_c(&padding, &to_dsp, &i, width);
	}
	write(1, to_dsp, i);
	ft_strdel(&to_dsp);
	return (i);
}