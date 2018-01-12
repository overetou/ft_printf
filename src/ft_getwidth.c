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