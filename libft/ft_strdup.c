/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:20:14 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 14:21:01 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*sdup;

	i = 0;
	len = ft_strlen(s);
	sdup = calloc(len, sizeof(char));
	while (i < len)
	{
		sdup[i] = s[i];
		i++;
	}
	return (sdup);
}
