/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:39 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/30 16:46:18 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"


int deal_key(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	ft_printf("Key event\n");
	return (1);
}

int	main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	int i;

	(void) argv;
	if (argc != 2)
	{
		ft_printf("Please run : ./fdf 'map_path'\n");
		return (0);
	}
	ft_printf("Start fdf\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Fdf window");
	i = 0;
	while (i < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 250, i,0x43C0A3);
		i++;
	}
	mlx_key_hook(win_ptr,deal_key,(void *)0);
	mlx_loop(mlx_ptr);
}
