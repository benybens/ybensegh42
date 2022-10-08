
#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int	len;
	int	i;
	char	*sdup;

	i = 0;
	len = ft_strlen(s);
	sdup = calloc(len,sizeof(char));
	while (i < len)
	{
		sdup[i] = s[i];
		i++;
	}
	return (sdup);
}
