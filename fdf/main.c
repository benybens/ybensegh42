/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:39 by yassinebens       #+#    #+#             */
/*   Updated: 2023/01/20 18:42:58 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	imagedata;
	t_list	*line_lst;
	t_list	**ptr_line_lst;
	int		fd;
	t_mapsize	mapsize;
	t_params mlx_params;
	t_point	**map_array;


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
	map_array = get_map_array(ptr_line_lst);
	
	ft_printf("--------Map array init------\n");
	mapsize = get_mapsize(ptr_line_lst);


	//print_map(map_array,mapsize);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1600, 800, "Fdf window");
	imagedata.img = mlx_new_image(mlx_ptr,1600,800);
	imagedata.addr = mlx_get_data_addr(imagedata.img, &imagedata.bits_per_pixel, &imagedata.line_length, &imagedata.endian);
	
	mlx_params.mlx = mlx_ptr;
	mlx_params.win = win_ptr;
	mlx_params.imagedata = &imagedata;
	mlx_params.start_point.x = -1;
	mlx_params.scale = 30;
	mlx_params.map_array = map_array;
	mlx_params.mapsize = &mapsize;
	mlx_params.winwidth = 1600;
	mlx_params.winheight = 800;
	mlx_params.canvasorigin.x = 0;
	mlx_params.canvasorigin.y = 0;
	
	mlx_mouse_hook(win_ptr,handle_mouse,&mlx_params);
	mlx_key_hook(win_ptr, handle_key, &mlx_params);

//==========================
//
// TRACE GRID
	//print_map(map_array,mapsize);

	project_iso_array(map_array,&mapsize);
	center_trace(map_array,&mapsize);
	trace_array(&imagedata,map_array,&mapsize,mlx_params.scale);
	//print_map(map_array,mapsize);
//
	
	ft_printf("--------ARRAY TRACED------\n");
//
//==========================
//	print_grid(win_ptr, mlx_ptr, ptr_line_lst, img);

	//=========================
	//
	
	mlx_put_image_to_window(&imagedata, win_ptr, imagedata.img,mlx_params.canvasorigin.x ,mlx_params.canvasorigin.y );

	mlx_loop(mlx_ptr);


	// Goal is to trace a line between two points

	}
