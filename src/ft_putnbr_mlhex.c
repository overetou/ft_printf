#include "ft_printf.h"

static int	ft_process(uintmax_t n, int i, char **to_dsp)
{
	char	base[] = "0123456789ABCDEF";
	
	if (n / 16 != 0)
		i = ft_process(n / 16, i, to_dsp);
	*to_dsp = ft_addchar(to_dsp, base[n % 16]);
	return (i + 1);
}

static int ft_handle_sharp(char **to_dsp, char *flags, uintmax_t n)
{
	if (n == 0)
		return (0);
	if (ft_detect(flags, '#'))
	{
		*to_dsp = ft_strfuse(to_dsp, "0X");
		return (2);
	}
	return (0);
}

int	ft_putnbr_mlhex(uintmax_t n, char *flags)
{
	int		i;
	char	*to_del;
	char	*to_dsp;
	int		width;
	char	*padding;

	ft_initialise(&to_dsp, &padding);
	i = ft_handle_sharp(&to_dsp, flags, n);
	i += ft_add_precision_mx(ft_process(n, 0, &to_dsp), ft_getprec(flags), &to_dsp, flags);
	if (ft_detect(flags, '.') && ft_getprec(flags) == 0 && n == 0)
		ft_set_to_null(&i, &to_dsp);
	if ((width = ft_getwidth(flags) - i) > 0)
	{
		if (ft_detect(flags, '-'))
			return (ft_padding_right(&to_dsp, width, i));
		else
		{
			ft_handle_null_mx(flags, &padding, &to_dsp, &to_del);
			i += ft_handle_wdth_x(width, &padding, &to_del, &to_dsp) + 1;
		}
	}
	ft_putstr(to_dsp);
	ft_strdel(&to_dsp);
	return (i);
}