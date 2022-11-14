/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:13 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/14 16:11:39 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main()
{
	int nbr;

	ft_printf("-----Starting test of libftprintf.a------\n");
	ft_printf("1/ This is a simple string\n");
	nbr = 15;
	ft_printf("2/ This is a string with 1 param, int -> %d\n",nbr);
	nbr = 0;
	ft_printf("3/ This is a string with 1 param, str -> %s\n","i am a string param");
	nbr = -98;
	ft_printf("4/ This is a string with 1 param, int -> %d\n",nbr);
	nbr = 124546;
	ft_printf("5/ This is a string with 1 param, int -> %d\n",nbr);
	nbr = -90;
	ft_printf("6/ This is a string with 2 params, int -> %d, int -> %s\n",nbr,":test:");
	nbr = 42;
/*	ft_printf("7/ This is a string with 2 params, int -> %d, int -> %d\n",nbr,nbr+2);
	nbr = 50;
	ft_printf("8/ This is a string with 2 params, int -> %d, int -> %d\n",nbr,nbr+2);
	nbr = 60;
	ft_printf("9/ This is a string with 3 params, int -> %d, int -> %d, int -> %d\n",nbr,nbr+2,nbr+4);
	nbr = 42;
	ft_printf("10/ This is a string with 3 params, int -> %d, int -> %d, int -> %d\n",nbr,nbr+2,nbr+4);
	nbr = 50;
	ft_printf("11/ This is a string with 3 params, int -> %d, int -> %d, int -> %d\n",nbr,nbr+2,nbr+4);
	nbr = 60;
	ft_printf("12/ This is a string with 4 params, str -> %s, str -> %s, str -> %s, str -> %s\n","a","b","c","d");
*/

}
