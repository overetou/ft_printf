#include "inc/ft_printf.h"
#include <limits.h>

int main(void)
{
	int i;
	i = ft_printf("10 en octet = %#X.\n", 15);
	ft_putnbr(i);
	return (0);	
}

