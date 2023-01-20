/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:54:11 by ybensegh          #+#    #+#             */
/*   Updated: 2023/01/20 18:27:29 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void project_iso_array(t_point **map_array, t_mapsize *mapsize)
{
    int y;
    int x;

    y = 0;

    while(y < mapsize->height)
	{
		x = 0;
		while(x < mapsize->width)
		{
            project_iso(&map_array[y][x]);
			x++;
		}	
		y++;
	}

}

void project_iso(t_point *point)
{
    int xraw;
    int yraw;


    xraw = point->x;
    yraw = point->y;
    point->x = xraw - yraw;
    point->y = xraw + yraw - point->z/9 ;

}
