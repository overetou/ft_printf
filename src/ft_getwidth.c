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
