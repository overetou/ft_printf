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