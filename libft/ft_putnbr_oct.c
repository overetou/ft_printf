#include "libft.h"

void	ft_putnbr_oct(unsigned int n)
{
	char	base[] = "01234567";
	
	if (n / 8 != 0)
		ft_putnbr_oct(n / 8);
	ft_putchar(base[n % 8]);
}
