/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:18:24 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/25 13:20:39 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dstlen;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	dstlen = ft_strlen(dst);
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
		dst[i] = 0;
	return (ft_strlen(src));
}
