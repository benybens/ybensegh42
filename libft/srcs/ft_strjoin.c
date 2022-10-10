
#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len_s1;
	int	len_s2;
	int	i;
	int	j;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	str = calloc(len_s1 + len_s2, sizeof(char));
	if(str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	return (str);
}
