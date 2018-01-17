#include "ft_printf.h"

static void ft_back(int *i, char **to_dsp)
{
	ft_strdel(to_dsp);
	*to_dsp = ft_makestr("0x");
	*i = 2;
}

static int	ft_process(unsigned long int n, int i, char **to_dsp)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		i = ft_process(n / 16, i, to_dsp);
	*to_dsp = ft_addchar(to_dsp, base[n % 16]);
	return (i + 1);
}

static int	ft_add_precision_p(int i, int prec, char **to_dsp)
{
	while (prec > i)
	{
		i++;
		*to_dsp = ft_strfuse(to_dsp, "0");
	}
	return (i);
}

int	ft_putnbr_p(unsigned long int n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	ft_initialise(&to_dsp, &padding);
	to_dsp = ft_makestr("0x");
	i = ft_add_precision_p(ft_process(n, 0, &to_dsp), ft_getprec(flags), &to_dsp) + 2;
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_back(&i, &to_dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right(&to_dsp, width, i));
		else
		{
			ft_handle_null_x(flags, &padding, &to_dsp, &to_del);
			i += ft_handle_wdth_x(width, &padding, &to_del, &to_dsp) + 1;
		}
	}
	ft_putstr(to_dsp);
	ft_strdel(&to_dsp);
	return (i);
}