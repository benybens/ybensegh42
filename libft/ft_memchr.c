/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:11 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 14:35:47 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*sc;
	unsigned int	i;

	i = 0;
	sc = (char *)s;
	while (i < n)
	{
		if (sc[i] == c)
			return (sc + i);
		i++;
	}
	return (NULL);
}
