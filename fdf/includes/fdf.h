/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <ybensegh@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:35:36 by yassinebens       #+#    #+#             */
/*   Updated: 2023/01/20 16:12:27 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <math.h>


typedef struct	s_mapsize {
	int height;
	int width;
}	t_mapsize;

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
	int z;
	int color;
}	t_point;

typedef struct	s_params {
	void	 *mlx;
	void	*win;
	t_point start_point;
	t_point end_point;
	t_data *imagedata;
	int scale;
	int xangle;
	int yangle;
	t_mapsize *mapsize;
	int **map_array;
	int winwidth;
	int winheight;
	t_point canvasorigin;
}	t_params;

void	    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	    trace_array(t_data *img, int **map_array, t_mapsize *mapsize, int scale, int xangle, int yangle);
void	    clear_image(t_params *mlx_params);
int         handle_key(int keycode, t_params *param);
int         handle_mouse(int mousecode,int x,int y, t_params *param);
void	    print_map(int **map_array,t_mapsize mapsize);
void	    parse_map(t_list **ptr_line_lst, int fd);
t_mapsize   get_mapsize(t_list **lst_points);
int	        count_points(t_list *lst_points);
void        trace_line(t_data *img_ptr, t_point a, t_point b, int color);
int	        **get_map_array(t_list **lst_points);