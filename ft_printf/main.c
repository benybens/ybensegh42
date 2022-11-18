/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:13 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/18 12:17:49 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main()
{
	char str[20] = "Hello";

//	printf("str  = %s , is stored at adress %p\n" , str , (void *)15);
//	ft_printf("str  = %s , is stored at adress %p\n" , str, 15);

	(void) str;
	printf("d: %d , x : %x\n", -9,-9);
	ft_printf("d: %d , u : %x\n", -9,-9);
	printf("d: %d , x : %X\n", 0x5fac,0x5fac);
	ft_printf("d: %d , u : %X\n", 0x5fac,0x5fac);

}
