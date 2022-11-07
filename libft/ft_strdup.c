/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:20:14 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/07 13:25:22 by ybensegh         ###   ########.fr       */
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
	sdup = calloc(len + 2, sizeof(char));
	if (sdup == NULL)
		return (NULL);
	while (i < len + 1)
	{
		sdup[i] = s[i];
		i++;
	}
	return (sdup);
}
