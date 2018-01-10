#include "inc/ft_printf.h"
#include <limits.h>

int main(void)
{
	//wchar_t p = 0;
	int i;

	//ft_printf("%p", &i);
	//i = prinft(1, "%u\n", L'α');
	i = printf("{% %}");
	ft_putnbr(i);
	return (0);	
}

