/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:13 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/17 16:09:48 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main()
{
	char str[20] = "Hello";

	printf("str  = %s , is stored at adress %p\n" , str , str);
	ft_printf("str  = %s , is stored at adress %p\n" , str, str);
}
