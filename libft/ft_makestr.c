#include "libft.h"

char	*ft_makestr(char *content)
{
	char *new;

	new = ft_strnew(ft_strlen(content) - 1);
	ft_strcpy(new, content);
	return (new);
}
