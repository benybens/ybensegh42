/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:49:01 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 13:55:23 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	int				j;
	unsigned int	cursor;

	i = 0;
	j = 0;
	cursor = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			cursor = i++;
			j++;
			while (little[j])
			{
				if (!(big[i++] == little[j++]))
					break ;
			}
			if (!little[j])
				return ((char *)big + cursor);
			i = cursor;
		}
		i++;
	}
	return (NULL);
}
