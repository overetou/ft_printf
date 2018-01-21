#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int i;

	setlocale(LC_ALL, "");
	i = ft_printf("%o", 41);
	printf("\n%d", i);
	return (0);	
}
