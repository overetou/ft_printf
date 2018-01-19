#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int i;

	setlocale(LC_ALL, "");
	i = ft_printf("{%010R}");
	printf("\n%d", i);
	return (0);	
}
