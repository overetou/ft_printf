#include "inc/ft_printf.h"

int main(void)
{
	char p[] = "yoyoyo";

	printf("%p", p);
	printf("%II#x", p);
	return (0);	
}

