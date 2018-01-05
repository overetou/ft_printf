#include "libft.h"

char	*ft_strfuse(char **str1, char *str2)
{
	str2 = ft_strjoin(*str1, str2);
	ft_strdel(str1);
	return (str2);
}