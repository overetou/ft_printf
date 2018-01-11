#include "inc/ft_printf.h"
#include <limits.h>

int main(void)
{
	int i;

	i = ft_printf("10 en decimal = %d.\n", -15);
	printf("%d", i);
	return (0);	
}

