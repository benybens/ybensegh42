
#include "../includes/libft.h"

int	wordlen(const char *s, char c)
{
	int i;

	i = 0;
	if(s[i] == 0)
		return (0);
	while (s[i] && s[i]!= c)
		i++;
	return (i); 
}

void	wordcpy(char *dest, const char *src, char c)
{
	int	i;
	
	i = 0;
	while (src[i] && src[i]!= c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}


char	**ft_split(char const *s, char c)
{
	int nc;
	int i;
	int j;
	char **split;

	nc = 0;
	i = 0;
	j = 0;
	while(s[i])
	{
		if (s[i] == c && nc == 0)
			nc += 2;
		else if (s[i] == c)
			nc ++;
		i++;
	}
	split = calloc(nc + 1, sizeof(char *));
	i = 0;
	while (j < nc)
	{
		split[j] = calloc (wordlen((s+i) + 1,c), sizeof(char));
		wordcpy(split[j], s + i, c);
		i += wordlen((s+i), c) + 1;
		j++;
	}
	return (split); 
}
