#include "libft.h"

void	ft_putnbr_mhex(unsigned int n)
{
	char	base[] = "0123456789ABCDEF";
	
	if (n / 16 != 0)
		ft_putnbr_mhex(n / 16);
	ft_putchar(base[n % 16]);
}