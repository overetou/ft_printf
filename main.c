#include "inc/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int	main()
{
	int i;
	wchar_t wc = 65537;
	wchar_t cut;

	cut = wc >> 6;
	setlocale(LC_ALL, "");
	i = printf("%S", L"Á±≥");
	ft_putnbr(i);
	//wc = wc >> 6;
	//ft_putnbr(128 | ((cut >> 12) ^ ((cut >> 12) << 6)));
	return (0);
}