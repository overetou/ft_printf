#include "libft.h"

int	ft_printf(char const *format, ...)
{
	ft_putnbr(ft_atoi(format));
	ft_putstr(format);
	return (0);
}
