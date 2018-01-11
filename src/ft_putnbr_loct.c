#include "ft_printf.h"

static int	ft_process(unsigned long int n, int i)
{
	char	base[] = "01234567";
	
	if (n / 8 != 0)
		i = ft_process(n / 8, i);
	ft_putchar(base[n % 8]);
	return (i + 1);
}

int	ft_putnbr_loct(unsigned long int n, int to_print)
{
	if (!n && !to_print)
		return (0);
	return (ft_process(n, 0));
}