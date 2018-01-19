#include "inc/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int i;

	setlocale(LC_ALL, "");
	i = printf("{% 03d}", 0);
	printf("\n%d", i);
	return (0);	
}
