
#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src,int c, size_t n)
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
		if(desti[i] == c)
		{
			dest = desti;
			i++;
			return(dest+i);
		}
		i++;
	}
	dest = desti;
	return(dest);
}
