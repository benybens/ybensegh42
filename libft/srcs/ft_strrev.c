
#include "../includes/libft.h"

char	*ft_strrev(char *s)
{
	int len;
	int i;
	char tmp;

	i = 0;
	len = ft_strlen(s);
	while ( i < len /2)
	{
		tmp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = tmp;
		i++;
	}
	return (s);
}

