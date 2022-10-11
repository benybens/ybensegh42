
#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;

	tmp = malloc(sizeof(char *));
	ft_memcpy(tmp,src,n);
	free(tmp);
	return(ft_memcpy(dest,src,n));
}
