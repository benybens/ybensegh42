
#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	char	*smod;

	i = 0;
	smod = calloc(ft_strlen(s), sizeof(char));
	while (s[i])
	{
		smod[i] = f(i, s[i]);
		i++;
	}
	smod[i] = 0;
	return (smod);
}

