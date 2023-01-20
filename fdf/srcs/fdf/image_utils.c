/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:03:03 by ybensegh          #+#    #+#             */
/*   Updated: 2023/01/20 18:45:24 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void trace_line(t_data *img_ptr, t_point a, t_point b, int color)
{
	int	dy;
	t_point		pxl;
	int e;
	int dx;
	int xinc = 1;
	int yinc = 1;
	int i;
	int xlen;
	int ylen;
	
	//ft_printf("Tracing line ...\n");
	if(a.x > b.x)
		xinc = -1;
	if(a.y > b.y)
		yinc = -1;
	e = abs(b.x - a.x);
	xlen = e;
	dx = 2 * e;
	dy = abs(b.y - a.y);
	ylen = dy;
	pxl = a;
	i = 0;
	if(xlen > ylen)
	{
		while(i <= xlen)
		{
			i++;
			my_mlx_pixel_put(img_ptr,pxl.x, pxl.y,color);
			e -= dy;
			if (e < 0)
			{
				pxl.y += yinc;
				e += dx;
			}
			pxl.x += xinc;
		}
	}
	else
	{
		while(i <= ylen)
		{
			i++;
			my_mlx_pixel_put(img_ptr,pxl.x, pxl.y,color);
			e -= dx;
			if (e < 0)
			{
				pxl.x += xinc;
				e += dy;
			}
			pxl.y += yinc;
		}
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}

void clear_image(t_params *mlx_params)
{
	int x;
	int y;

	y = 0;

	while (y < mlx_params->winheight)
	{
		x = 0;
		while (x < mlx_params->winwidth)
		{
			my_mlx_pixel_put(mlx_params->imagedata,x, y,0x0);
			x++;
		}
		y++;
	}
	ft_printf("Clean image ready");
	mlx_put_image_to_window(mlx_params->imagedata, mlx_params->win, mlx_params->imagedata->img,0 ,0);
}

void	trace_array(t_data *imgdata, t_point **map_array, t_mapsize *mapsize,int scale)
{
	t_point pa;
	t_point pb;
	int y;
	int x;
    
    y = 0;
	while(y < mapsize->height)
	{
		x = 0;
		while(x < mapsize->width)
		{
			pa.x = map_array[y][x].x * scale;
			pa.y = map_array[y][x].y * scale;
            if (x < mapsize->width-1)
            {
                pb.x = map_array[y][x+1].x * scale;
			    pb.y = map_array[y][x+1].y * scale;
                trace_line(imgdata, pa, pb, 0xFFFFFF);
            }
            if (y < mapsize->height-1)
            {
                pb.x = map_array[y+1][x].x * scale ;
			    pb.y = map_array[y+1][x].y * scale;
			    trace_line(imgdata, pa, pb, 0xFFFFFF);

            }
			

			x++;
		}	
		y++;
	}
}

void center_trace(t_point **map_array, t_mapsize *mapsize)
{
    int y, x;

    for (y = 0; y < mapsize->height; y++)
    {
        for (x = 0; x < mapsize->width; x++)
        {
            map_array[y][x].x += 15;
            map_array[y][x].y += 0;
        }
    }
}