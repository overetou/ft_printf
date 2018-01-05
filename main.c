#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	//wchar_t 	wc = 945;
	char *pointeur;

	pointeur = ft_makestr("coucou");
	printf("0x%x\n", &pointeur);
	printf("%p\n", pointeur);
	ft_strdel(&pointeur);
	setlocale(LC_ALL, "");
	return (0);	
}
