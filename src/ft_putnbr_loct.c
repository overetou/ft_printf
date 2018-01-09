#include "ft_printf.h"

int	ft_putnbr_loct(unsigned long int n, int i)
{
	char	base[] = "01234567";
	
	if (n / 8 != 0)
		i = ft_putnbr_loct(n / 8, i);
	ft_putchar(base[n % 8]);
	return (i + 1);
}