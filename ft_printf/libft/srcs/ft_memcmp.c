
#include "../includes/libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;

	char *s1c;
	char *s2c;

	i = 0;
	s1c = (char *)s1;
	s2c = (char *)s2;
	while(i < n)
	{
		if(s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		i++;
	}
	return (0);
}
