/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:39 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/30 15:12:01 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void) argv;
	if(argc != 2)
	{
		ft_printf("Please run : ./fdf 'map_path'\n");
		return(0);
	}
	ft_printf("Start fdf\n");
}
