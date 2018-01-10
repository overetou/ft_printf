#include "ft_printf.h"

int	ft_putwstr(wchar_t *wstr)
{
	int s;

	if (!wstr)
	{
		ft_putstr("(null)");
		return (6);
	}
	s = 0;
	while (*wstr)
		s += ft_putwchar(*wstr++);
	return (s);
}