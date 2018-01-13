#include "ft_printf.h"

int	ft_putpercent(char *flags)
{
	int width;
	int i;

	width = ft_getwidth(flags) - 1;
	i = 1;
	if (ft_detect(flags, '-'))
	{
		ft_putchar('%');
		while (width-- > 0)
			i += ft_putchar(' ');
		return (i);
	}
	while (width-- > 0)
		i += ft_putchar(' ');
	ft_putchar('%');
	return (i);
}