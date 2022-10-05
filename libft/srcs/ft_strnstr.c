
#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	int		j;
	unsigned int	cursor;

	i = 0;
	j = 0;
	cursor = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			cursor = i;
			i++;
			j++;
			while (little[j])
			{
				if(big[i] == little[j])
				{
					i++;
					j++;
				}
				else
				{
					break;
				}
			}
			if(!little[j])
				return((char *)big+cursor);
			i = cursor; 
		}
		i++;
	}

	return (NULL);

}
