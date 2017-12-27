#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

char *ft_create_binary(unsigned int n, unsigned int x)
{
	char *bin;
	char c[1];
	char *to_del;

	if (n / 2 == 0)
		to_del = ft_strnew(0);
	else
		to_del = ft_create_binary(n / 2, x++);
	c[0] = n % 2 + '0';
	bin = ft_strjoin(to_del, c);
	ft_strdel(&to_del);
	return (bin);
}

void	ft_putwchar(wchar_t wc)
{
    char	*bin;
    size_t	b_size;
    char	*oct;

    bin = ft_create_binary(wc, 0);
    b_size = ft_strlen(bin);
    if (b_size < 8)
    	ft_putchar(wc);
    else if (b_size < 12)
    	strcpy(oct, "110xxxxx 10xxxxxx");
    else if (b_size < 17)
    	strcpy(oct, "1110xxxx 10xxxxxx 10xxxxxx");
    else
    	strcpy(oct, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
    ft_fill_mask(oct, bin);
    ft_strdel(&bin);
    while (oct)
    	write(1, ft_get_next_dec(&oct), 1);
}

int	main(void)
{
	wchar_t 	wc = 0x1234;
	
	//ft_putwchar(wc);
	setlocale(LC_ALL, "");
	ft_putwchar(wc);
	//ft_printf("%c\n", ft_putwchar());
	//printf("%lc\n", wc);
	return (0);	
}
