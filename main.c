#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int i;

	i = printf("%.9p", 1234);
	printf("\n%d", i);
	return (0);	
}

