#include "inc/ft_printf.h"
#include <limits.h>

int main(void)
{
	int i;

	i = printf("%5.10d\n", -42);
	printf("%d", i);
	return (0);	
}

