/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:58 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/07 13:12:44 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*intmin_print(void)
{
	char	*nba;

	nba = calloc(12, sizeof(char));
	ft_strlcpy(nba, "-2147483648", 12);
	return (nba);
}

char	*ft_itoa(int nb)
{
	char	*nba;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (nb == INT_MIN)
		return (intmin_print());
	if (nb < 0)
	{
		nb = -nb;
		sign = -sign;
	}
	nba = calloc(nb % 10 + 2, sizeof(int));
	while (nb >= 10)
	{
		nba[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	nba[i++] = (nb % 10) + '0';
	if (sign < 0)
		nba[i] = '-';
	return (ft_strrev(nba));
}
