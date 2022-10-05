
#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while(dst[i])
		i++;
	while(src[j] && j < size -1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return(ft_strlen(src) + ft_strlen(dst));
}
