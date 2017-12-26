#include "libft.h"

void	ft_putnbr_hex(unsigned int n)
{
	char	base[] = "0123456789abcdef";
	
	if (n / 16 != 0)
		ft_putnbr_hex(n / 16);
	ft_putchar(base[n % 16]);
}
