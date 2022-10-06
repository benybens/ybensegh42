
#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c , size_t n)
{
	char		*sc;
	unsigned int	i;

	i = 0;
	sc = (char *)s;
	while (i < n)
	{
		if (sc[i] == c)
			return (sc + i);
		i++;
	}
	return (NULL);
}
