/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:52:16 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 11:53:35 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (nptr[i])
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}
