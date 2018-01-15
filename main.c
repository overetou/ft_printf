#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int i;

	i = ft_printf("%.d, %.0d", 0, 0);
	printf("\n%d\n", i);
	return (0);	
}

