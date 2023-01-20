/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:56:22 by ybensegh          #+#    #+#             */
/*   Updated: 2023/01/20 16:13:51 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int handle_key(int keycode, t_params *param)
{
	if(keycode == 53)
	{
		ft_printf("Bye !");
		mlx_destroy_window(param->mlx,param->win);
		exit(0);
	}
	if(keycode == 31)
	{
		ft_printf("O Pressed = Scale up");
		param->scale += 1;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 35)
	{
		ft_printf("P Pressed = Scale down");
		param->scale -= 1;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 123)
	{
		ft_printf("left Pressed = x rot min");
		param->xangle -= 10;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 124)
	{
		ft_printf("right Pressed = x rot pos");
		param->xangle += 10;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 125)
	{
		ft_printf("down Pressed = y rot min");
		param->yangle -= 10;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 126)
	{
		ft_printf("left Pressed = x rot min");
		param->yangle += 10;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 38)
	{
		ft_printf("left Pressed = x pan  min");
		param->canvasorigin.x -= 50;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 37)
	{
		ft_printf("right Pressed = x pan pos");
		param->canvasorigin.x += 50;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 40)
	{
		ft_printf("down Pressed = y pan min");
		param->canvasorigin.y += 50;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}
	if(keycode == 34)
	{
		ft_printf("left Pressed = y pan pos");
		param->canvasorigin.y -= 50;
		clear_image(param);
		trace_array(param->imagedata,param->map_array,param->mapsize,param->scale,param->xangle,param->yangle);
	}



	mlx_put_image_to_window(&param->imagedata, param->win, param->imagedata->img,param->canvasorigin.x ,param->canvasorigin.y);
	return (1);
}

int	handle_mouse(int mousecode,int x,int y, t_params *param)
{
	if(mousecode == 1)
	{
		if(param->start_point.x == -1)
		{
			ft_printf("Save first point\n");
			param->start_point.x = x;
			param->start_point.y = y;
		}
		else
		{
			ft_printf("Save second point\n");
			param->end_point.x = x;
			param->end_point.y = y;
			trace_line(param->imagedata, param->start_point, param->end_point, 0xFFFFFF);
			mlx_put_image_to_window(&param->imagedata, param->win, param->imagedata->img,0 ,0);
			param->start_point.x = -1;
		}
	}
		if(mousecode == 2)
		ft_printf("Right Click\n");
	return (1);
}