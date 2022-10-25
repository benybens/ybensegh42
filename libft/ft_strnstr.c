/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:49:01 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/25 16:28:31 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cursor;

	i = 0;
	cursor = 0;
	if (little[0] == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			cursor = i++;
			j++;
			while (little[j])
			{
				if (!(big[i++] == little[j++]))
					break ;
			}
			if ((little[j] == 0 || little[j] == ' ') && j == ft_strlen(little) - 1)
				return ((char *)big + cursor);
			i = cursor;
		}
		i++;
	}
	return (NULL);
}
