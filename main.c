#include "inc/ft_printf.h"
#include <limits.h>

int main(void)
{
	char p[] = "yoyoyo\n";
	int i;
	//wchar_t

	//ft_printf("%p", &i);
	i = printf("%C", 'c');
	ft_putnbr(i);
	return (0);	
}

