/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:22:10 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/02 00:09:15 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	wordcpy(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	init_split_var(int *i1, int *i2, int *i3)
{
	*i1 = 0;
	*i2 = 0;
	*i3 = 0;
}

char	**ft_split(char const *s, char c)
{
	int		nc;
	int		i;
	int		j;
	char	**split;

	init_split_var(&nc, &i, &j);
	while (s[i])
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
		split[j] = calloc (wordlen((s + i) + 1, c), sizeof(char));
		wordcpy(split[j], s + i, c);
		i += wordlen((s + i), c) + 1;
		j++;
	}
	split[j] = NULL;
	return (split);
}
