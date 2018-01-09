#include "inc/ft_printf.h"

int main(void)
{
	char p[] = "yoyoyo\n";
	int i = 5;
	//wchar_t

	i = (ft_printf("%p\n", &i));
	ft_putnbr(i);
	ft_putchar('\n');
	i = (printf("%p\n", &i));
	ft_putnbr(i);
	return (0);	
}

