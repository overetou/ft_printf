#include "libft.h"

int	ft_power(int base, int power)
{
	int r;

	r = 1;
	while (power--)
		r = r * base;
	return (r);
}
