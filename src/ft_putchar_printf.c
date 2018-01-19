#include "ft_printf.h"
#include <unistd.h>

void	ft_handle_width_c(char **padding, char **to_dsp, int *i, int width)
{
	char *to_del;

	while (width > (*i)++)
		*padding = ft_addchar(padding, **padding);
	to_del = *to_dsp;
	*to_dsp = ft_strfuse(padding, *to_dsp);
	ft_strdel(&to_del);
}

int		ft_putchar_printf(char c, char *flags)
{
	int		i;
	char	*to_dsp;
	int		width;
	char	*padding;

	ft_initialise(&to_dsp, &padding);
	to_dsp =  ft_strnew(0);
	to_dsp = ft_addchar(&to_dsp, c);
	i = 1;
	if ((width = ft_getwidth(flags)) > i)
	{
		width--;
		if (ft_detect(flags, '-'))
			return (ft_padding_right(&to_dsp, width, i));
		else
		{
			if (ft_detect(flags, '0'))
				*padding = '0';
			ft_handle_width_c(&padding, &to_dsp, &i, width);
		}
	}
	write(1, to_dsp, i);
	ft_strdel(&to_dsp);
	return (i);
}