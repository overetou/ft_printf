#include "ft_printf.h"

short ft_detect(char *flags, char to_find)
{
	while (*flags)
	{
		if (*flags++ == to_find)
			return (1);
	}
	return (0);
}

int	ft_count(char *flags, char to_find)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (*flags++ == to_find)
			i++;
	}
	return (i);
}