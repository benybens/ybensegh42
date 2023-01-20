/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:06:44 by ybensegh          #+#    #+#             */
/*   Updated: 2023/01/20 16:13:33 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	**get_map_array(t_list **lst_points)
{
	t_mapsize	mapsize;
	int **map_array;
	int	y;
	int x;
	t_list *current_line;
	t_list *next_line;
	char **line_splitted;

	y = 0;
	current_line = lst_points[0];
	next_line = current_line->next;
	mapsize = get_mapsize(lst_points);
	map_array = ft_calloc(mapsize.height * 2, sizeof(int));
	while(y < mapsize.height)
	{
		map_array[y] = ft_calloc(mapsize.width,sizeof(int));
		y++;
	}
	x = 0;
	y = 0;
	while(y < mapsize.height)
	{
		x = 0;
		line_splitted = ft_split(current_line->content,' ');
		//ft_printf("Split line %i\n",y);
		while(x < mapsize.width)
		{
			map_array[y][x] = ft_atoi(line_splitted[x]);
		//	ft_printf("%i/",map_array[y][x]);
			x++;
		}
		//ft_printf("\n");
		free(line_splitted);
		if(next_line)
		{
			current_line = next_line;
			next_line = next_line->next;
		}
		y++;
	}	
	return (map_array);

}