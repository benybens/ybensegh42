/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:15:44 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 14:16:18 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*smod;

	i = 0;
	smod = calloc(ft_strlen(s), sizeof(char));
	while (s[i])
	{
		smod[i] = f(i, s[i]);
		i++;
	}
	smod[i] = 0;
	return (smod);
}
