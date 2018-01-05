#include "libft.h"

void	ft_putwstr(wchar_t *str)
{
	while (*str)
		ft_putwchar(*str++);
}
