#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int i;

	i = printf("%#o", 0);
	printf("\n%d", i);
	return (0);	
}

