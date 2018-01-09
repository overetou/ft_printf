#include "ft_printf.h"

static int	ft_put_pointer(long int n, int i)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		i = ft_put_pointer(n / 16, i);
	ft_putchar(base[n % 16]);
	return (i + 1);
}

int			ft_putnbr_lhex(long int n)
{
	ft_putstr("0X");
	return (ft_put_pointer(n, 2));
}