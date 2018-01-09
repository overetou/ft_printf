#include "ft_printf.h"
#include "limits.h"

int	ft_putnbr_l(long int n)
{
	long int		mem;
	long int		div;
	long int		i;

	i = 0;
	if (n < 0)
	{
		if (n == LONG_MIN)
		{
			ft_putstr("-9223372036854775808");
			return (20);
		}
		ft_putchar('-');
		n = -n;
		i++;
	}
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		mem = (n / div);
		ft_putchar(mem + '0');
		n = n - (mem * div);
		div = div / 10;
		i++;
	}
	return (i);
}