#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int i;

	i = ft_printf("%#08x", 42);
	printf("\n%d", i);
	return (0);	
}

