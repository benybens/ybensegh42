/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:16:48 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/25 16:04:32 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dstlen;

	i = 0;
	j = 0;
	if (size <= 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	while (dst[i])
		i++;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = 0;
	if (size + ft_strlen(src) < dstlen + ft_strlen(src))
		return (size + ft_strlen(src));
	else
		return (dstlen + ft_strlen(src));
}
