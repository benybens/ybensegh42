/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:39 by yassinebenseg     #+#    #+#             */
/*   Updated: 2023/01/09 13:52:12 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/mlx.h"
#include "./includes/libft.h"
#include <math.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_point {
	int x;
	int y;
}	t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void trace_line(t_data *img_ptr, t_point a, t_point b, int color)
{
	int	dy;
	t_point		pxl;
	int e;
	int dx;
	int xinc = 1;
	int yinc = 1;
	int i;
	int length;

	if(a.x > b.x)
		xinc = -1;
	if(a.y > b.y)
		yinc = -1;
	e = abs(b.x - a.x);
	length = e;
	dx = 2 * e;
	dy = abs(b.y - a.y);
	pxl = a;
	i = 0;
	while(i <= length)
	{
		i++;
		ft_printf("pxl x : %i\n",pxl.x);
		ft_printf("pxl y : %i\n",pxl.y);
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



int	deal_key(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	ft_printf("Key event\n");
	return (1);
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

void	print_map(t_list **ptr_line_list)
{	
	char *line;
	t_list *next_line;

	next_line = ptr_line_list[0];
	line = next_line->content;
	while(next_line)
	{
		ft_printf("%s",line);
		next_line = next_line->next;
		if(next_line)
			line = next_line->content;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img_ptr;
	t_list	*line_lst;
	t_list	**ptr_line_lst;
	int		fd;
	t_point start;
	t_point end;
	


	(void) argv;
	if (argc != 2)
	{
		ft_printf("Please run : ./fdf 'map_path'\n");
		return (0);
	}
	ft_printf("Start fdf\n");
	fd = open(argv[1],O_RDONLY);
	line_lst = ft_lstnew(get_next_line(fd));
	ptr_line_lst = &line_lst;
	parse_map(ptr_line_lst,fd);
	print_map(ptr_line_lst);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "Fdf window");
	img_ptr.img = mlx_new_image(mlx_ptr,1000,800);
	img_ptr.addr = mlx_get_data_addr(img_ptr.img, &img_ptr.bits_per_pixel, &img_ptr.line_length, &img_ptr.endian);

	start.x = 200;
	start.y = 200;

	end.x = 300;
	end.y = 190;
	trace_line(&img_ptr, start, end,0x00FF00);
	
	start.x = 200;
	start.y = 200;

	end.x = 300;
	end.y = 210;
	trace_line(&img_ptr, start, end,0x00FF00);

	start.x = 200;
	start.y = 200;

	end.x = 300;
	end.y = 800;
	trace_line(&img_ptr, start, end,0x00FF00);

	start.x = 200;
	start.y = 200;

	end.x = 300;
	end.y = 10;
	trace_line(&img_ptr, start, end,0x00FF00);

	start.x = 200;
	start.y = 200;

	end.x = 100;
	end.y = 10;
	trace_line(&img_ptr, start, end,0xFF0000);

	start.x = 200;
	start.y = 200;

	end.x = 100;
	end.y = 190;
	trace_line(&img_ptr, start, end,0xFF0000);

	start.x = 200;
	start.y = 200;

	end.x = 100;
	end.y = 210;
	trace_line(&img_ptr, start, end,0xFF0000);

	start.x = 200;
	start.y = 200;

	end.x = 100;
	end.y = 800;
	trace_line(&img_ptr, start, end,0xFF0000);
	mlx_put_image_to_window(&img_ptr, win_ptr, img_ptr.img,0 ,0);
	mlx_key_hook(win_ptr,deal_key,(void *)0);
	mlx_loop(mlx_ptr);


	// Goal is to trace a line between two points

	}
