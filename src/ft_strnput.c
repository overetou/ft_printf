#include "ft_printf.h"

void	ft_strnput(char *str, int n)
{
	int i;

	i = 0;
	while (i != n)
		ft_putchar(str[i++]);
}