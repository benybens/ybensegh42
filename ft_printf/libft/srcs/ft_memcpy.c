
#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char		*desti;
	char		*srci;

	i = 0;
	desti = (char *)dest;
	srci = (char *)src;
	while(i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	dest = desti;
	return(dest);
}
