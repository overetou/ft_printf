#include "inc/ft_printf.h"
#include <limits.h>

int main(void)
{
	int i;

	i = ft_printf("%0+-5d\n", 42);
	printf("%d", i);
	return (0);	
}

