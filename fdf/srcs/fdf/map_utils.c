/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:51 by ybensegh          #+#    #+#             */
/*   Updated: 2023/01/20 16:13:46 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	print_map(int **map_array,t_mapsize mapsize)
{	
	int x;
	int y;

	x = 0;
	y = 0;
	
	while(y < mapsize.height)
	{
		//ft_printf("line %i: ", y + 1);
		x = 0;
		while(x < mapsize.width)
		{
			ft_printf("%i.",map_array[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	parse_map(t_list **ptr_line_lst, int fd)
{
	t_list *line_lst;

	while(1)
	{
		line_lst = ft_lstnew(get_next_line(fd));
		if(line_lst->content == NULL)
			break;
		ft_lstadd_back(ptr_line_lst, (void *)line_lst); 
	}
}

t_mapsize get_mapsize(t_list **lst_points)
{
	t_mapsize	mapsize;

	mapsize.width = count_points(lst_points[0]);
	mapsize.height = ft_lstsize(lst_points[0]);
	ft_printf("map size is %i x %i\n",mapsize.width,mapsize.height);
	return (mapsize);
}

int	count_points(t_list *lst_points)
{
	int n;
	int i;
	char *str;
	int isspace;

	str = (char *)lst_points->content;
	n = 0;
	isspace = 1;
	i = 0;
	//ft_printf("--------------------- COUNT POINTS-------- \n",str);
	while( str[i] != 0)
	{
		if(ft_isdigit(str[i]))
		{
			//ft_printf("--->is num\n",str);
			if(isspace)
			{
				isspace = 0;
				//ft_printf("--------> n + 1 \n",str);
				n++;
			}
		}
		else
		{
			if(!isspace)
			{
				isspace = 1;
			}
		}
		i++;
	}
	return (n);
}