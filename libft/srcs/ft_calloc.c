
#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (char *)malloc(nmemb * size);
	while(i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return(ptr);
}
