/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:53 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 16:20:54 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	findset(int *isset, int *i, char const *s1, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (s1[*i] == set[j])
		{
			*isset = 1;
			break ;
		}
		*isset = 0;
		j++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		isset;
	int		bounds[2];

	i = 0;
	isset = 1;
	str = calloc(ft_strlen(s1), sizeof(char));
	while (s1[i++] && isset)
		findset(&isset, &i, s1, set);
	bounds[0] = --i;
	isset = 1;
	i = ft_strlen(s1) - 1;
	while (s1[i--] && isset)
		findset(&isset, &i, s1, set);
	bounds[1] = i;
	ft_strlcpy(str, s1 + bounds[0], bounds[1] - bounds[0] + 2);
	return (str);
}
