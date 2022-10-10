
#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	i;
	int	j;
	int	isset;
	int	start;
	int	end;

	i = 0;
	isset = 1;
	str = calloc(ft_strlen(s1), sizeof(char));
	while (s1[i] && isset)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				isset = 1;
				i++;
				break;
			}
			isset = 0;
			j++;
		}
	}
	start = i;
	isset = 1;
	i = ft_strlen(s1);
	i--; //avoid /0
	while (s1[i] && isset)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				isset = 1;
				i--;
				break;
			}
			isset = 0;
			j++;
		}
	}
	end = i;
	ft_strlcpy(str, s1 + start, end - start + 2); // +2 because twos /0
	return (str);
}
