#include "ft_printf.h"

int	ft_getwidth(char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] > '0' && flags[i] <= '9')
		{
			if (i)
			{
				if (flags[i - 1] != '.')
					return (ft_atoi(flags + i));
			}
			else
				return (ft_atoi(flags + i));
		}
		i++;
	}
	return (0);
}

int		ft_add_precision(int i, int prec, char **to_dsp)
{
	char *to_add;
	char *to_del;

	if (prec <= i)
		return (i);
	to_add = ft_strnew(0);
	if (**to_dsp == '+' || **to_dsp == '-' || **to_dsp == ' ')
	{
		to_add = ft_addchar(&to_add, **to_dsp);
		**to_dsp = '0';
		i++;
	}
	while (prec > i)
	{
		i++;
		to_add = ft_addchar(&to_add, '0');
	}
	to_del = *to_dsp;
	*to_dsp = ft_strfuse(&to_add, *to_dsp);
	ft_strdel(&to_del);
	return (i);
}

void	ft_handle_null(char *flags, char **padding, char **to_dsp, char **to_del)
{
	*to_del = ft_makestr(" ");
	if (ft_detect_0(flags))
	{
		**padding = '0';
		if (**to_dsp == '+' || **to_dsp == '-')
		{
			**to_del = **to_dsp;
			**to_dsp = **padding;
		}
	}
}

int		ft_handle_wdth(int width, char **padding, char **to_del, char **to_dsp)
{
	int i;

	i = 0;
	while (--width)
	{
		i++;
		*padding = ft_addchar(padding, **padding);
	}
	if (**to_del != ' ')
			**padding = **to_del;
		ft_strdel(to_del);
		*to_del = *to_dsp;
		*to_dsp = ft_strfuse(padding, *to_dsp);
	ft_strdel(to_del);
	ft_strdel(padding);
	return (i);
}

void	ft_handle_null_x(char *flags, char **padding, char **to_dsp, char **to_del)
{
	if (ft_detect_0(flags))
	{
		**padding = '0';
		if (ft_detect(flags, '#'))
		{
			*to_del = ft_makestr("0x");
			(*to_dsp)[1] = '0';
			return ;
		}
	}
	*to_del = ft_makestr(" ");
}

int		ft_handle_wdth_x(int width, char **padding, char **to_del, char **to_dsp)
{
	int i;

	i = 0;
	while (--width)
	{
		i++;
		*padding = ft_addchar(padding, **padding);
	}
	if (**to_del != ' ')
		ft_strncpy(*padding, *to_del, 2);
	ft_strdel(to_del);
	*to_del = *to_dsp;
	*to_dsp = ft_strfuse(padding, *to_dsp);
	ft_strdel(to_del);
	ft_strdel(padding);
	return (i);
}

int	ft_add_precision_x(int i, int prec, char **to_dsp, char *flags)
{
	char *to_add;
	char *to_del;

	if (prec <= i)
		return (i);
	to_add = ft_strnew(0);
	if (ft_detect(flags, '#'))
	{
		to_add = ft_strfuse(&to_add, "0x");
		(*to_dsp)[1] = '0';
		i += 2;
	}
	while (prec > i)
	{
		i++;
		to_add = ft_addchar(&to_add, '0');
	}
	to_del = *to_dsp;
	*to_dsp = ft_strfuse(&to_add, *to_dsp);
	ft_strdel(&to_del);
	return (i);
}

int	ft_add_precision_mx(int i, int prec, char **to_dsp, char *flags)
{
	char *to_add;
	char *to_del;

	if (prec <= i)
		return (i);
	to_add = ft_strnew(0);
	if (ft_detect(flags, '#'))
	{
		to_add = ft_strfuse(&to_add, "0X");
		(*to_dsp)[1] = '0';
		i += 2;
	}
	while (prec > i)
	{
		i++;
		to_add = ft_addchar(&to_add, '0');
	}
	to_del = *to_dsp;
	*to_dsp = ft_strfuse(&to_add, *to_dsp);
	ft_strdel(&to_del);
	return (i);
}

void	ft_handle_null_mx(char *flags, char **padding, char **to_dsp, char **to_del)
{
	if (ft_detect_0(flags))
	{
		**padding = '0';
		if (ft_detect(flags, '#'))
		{
			*to_del = ft_makestr("0X");
			(*to_dsp)[1] = '0';
			return ;
		}
	}
	*to_del = ft_makestr(" ");
}

int ft_padding_right(char **to_dsp, int width, int i)
{
	ft_putstr(*to_dsp);
	ft_strdel(to_dsp);
	while (width--)
		i += ft_putchar(' ');
	return (i);
}

int	ft_getprec(char *flags)
{
	while (*flags)
	{
		if (*flags++ == '.')
			return (ft_atoi(flags));
	}
	return (0);
}

short	ft_detect_0(char *flags)
{
	if (ft_detect(flags, '.'))
		return (0);
	while (*flags)
	{
		if (*flags == '0' && (*(flags - 1) < '1' || *(flags - 1) > '9'))
			return (1);
		flags++;
	}
	return (0);
}

void	ft_set_to_null(int *i, char **to_dsp)
{
	*i = 0;
	ft_strdel(to_dsp);
	*to_dsp = ft_strnew(0);
}

void	ft_initialise(char **to_dsp, char **padding)
{
	*to_dsp = ft_strnew(0);
	*padding = ft_makestr(" ");
}
